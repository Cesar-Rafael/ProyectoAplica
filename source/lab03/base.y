%{
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
/* prototipos de funcion */
int yylex();
void yyerror(char *s);

// Se hizo la corrección de errores, ahora compila y corre 
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

/*estructuras*/
char lexema[100];
FILE * arch;

%}
%token Y_LOGICO TIPO_BOOLEAN BUCLE_SALIDA TIPO_CARACTER BUCLE_CONTINUACION TIPO_DOUBLE CONDICION_SINO FIN FALSO BUCLE_FOR FUNCION_INICIO CONDICION_INICIO ENTRADA TIPO_ENTERO OPERACION_MODULAR NEGACION_LOGICA O_LOGICO SALIDA FUNCION_RETORNO TIPO_CADENA VERDADERO VARIABLE BUCLE_WHILE OPERACION_SUMA OPERACION_RESTA OPERACION_MULTIPLICACION OPERACION_DIVISION OPERACION_POTENCIA DISYUNCION_BINARIA NEGACION_BINARIA CONJUNCION_BINARIA LEFT_SHIFT RIGHT_SHIFT DISYUNCION_EXCLUSIVA_BINARIA FIN_DE_INSTRUCCION SEPARACION_VARIABLES INICIO INICIO_FIN_CADENA INICIO_FIN_CARACTER PARENTESIS_IZQUIERDA PARENTESIS_DERECHA CORCHETE_IZQUIERDA CORCHETE_DERECHA MENOR_QUE MAYOR_QUE MENOR_O_IGUAL_QUE MAYOR_O_IGUAL_QUE COMENTARIO_EN_LINEA INICIO_FIN_COMENTARIO_EN_BLOQUE ASIGNACION ASIGNACION_PROFUNDA IGUALDAD DESIGUALDAD INCREMENTO_EN_UNIDAD DECREMENTO_EN_UNIDAD CONDICION_UNICA INCREMENTO_DIRECTO DECREMENTO_DIRECTO MULTIPLICACION_DIRECTA DIVISION_DIRECTA NUMERO_ENTERO NUMERO_REAL IDENTIFICADOR

%%

listainst: listainst instr  | instr  ;
instr :  asignacion ';'
asignacion: IDENTIFICADOR '=' expression;
expression: expression '+' term { $$ = $1 + $3; };

expression: expression '-' term { $$ = $1 - $3; };
term: term '*' fact { $$ = $1 * $3; };
term: term '/' fact { $$ = $1 / $3; };

term: term OPERACION_POTENCIA fact { $$=pow($1,$3); };
term: term LEFT_SHIFT fact { $$=$1<<$3; };
term: term RIGHT_SHIFT fact { $$=$1>>$3; };
term: term '&' fact { $$ = $1 & $3; };
term: term '^' fact { $$ = $1 ^ $3; };
term: term '|' fact { $$ = $1 | $3; };
expression: term  { $$ = $1;};

term: fact { $$ = $1; };
term: '~'fact { $$ = ~$2; };
term: term '=' fact { $1 = $3; };
fact: NUMERO_ENTERO { $$ = $1; };
fact: '(' expression ')' { $$ = $2; };

%%

int main(void) {
    arch = fopen("../../tests/lab03/test04.raa", "r");
    if (arch == NULL) {
        printf("ERROR: No se ha abierto el archivo test01.raa correctamente.\n");
        exit(1);
    }
    if (!yyparse()) {
        printf("Cadena valida\n");
    } else {
        printf("Cadena invalida\n");
    }
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

/*
 * Metodo: EsBuenCatacter
 * Uso: int resultado = EsBuenCaracter('_');
 * -----------------------------------------
 * Retorna el valor de verdad si es que el caracter es valido para algun identificador.
 */

int EsBuenCaracter(char c) {
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' && '0' <= c || c <= '9' || c == '_';
}

int yylex() {
    char c;
    int pos;
    while (isspace((c = fgetc(arch))) continue;
    if (c == '\n') return c;
    if (c == EOF) return 0;
    /*
     * Caso 1:
     * Si el token comienza con una letra del alfabeto o guion bajo tenemos las siguientes posibilidades:
     * Todas son letras del alfabeto. Verifico si es que es palabra reservada para retornarla.
     * En otro caso, necesariamente es un identificador
     */

    if (isalpha(c) || c == '_') {
        pos = 0;
        do {
            lexema[pos++] = c;
            c = fgetc(arch);
        } while (EsBuenCaracter(c));
        ungetc(c, arch);
        lexema[pos++] = '\0';
        int solo_alfabeto = 1;
        for (int i = 0; i < pos - 1; i++) {
            if (!isalpha(lexema[i])) {
                solo_alfabeto = 0;
                break;
            }
        }
        if (solo_alfabeto) {
            if (strcmp(lexema, "and")) return Y_LOGICO;
            if (strcmp(lexema, "bool")) return TIPO_BOOLEAN;
            if (strcmp(lexema, "break")) return BUCLE_SALIDA;
            if (strcmp(lexema, "char")) return TIPO_CARACTER;
            if (strcmp(lexema, "continue")) return BUCLE_CONTINUACION;
            if (strcmp(lexema, "double")) return TIPO_DOUBLE;
            if (strcmp(lexema, "else")) return CONDICION_SINO;
            if (strcmp(lexema, "end")) return FIN;
            if (strcmp(lexema, "false")) return FALSO;
            if (strcmp(lexema, "for")) return BUCLE_FOR;
            if (strcmp(lexema, "function")) return FUNCION_INICIO;
            if (strcmp(lexema, "if")) return CONDICION_INICIO;
            if (strcmp(lexema, "input")) return ENTRADA;
            if (strcmp(lexema, "int")) return TIPO_ENTERO;
            if (strcmp(lexema, "mod")) return OPERACION_MODULAR;
            if (strcmp(lexema, "not")) return NEGACION_LOGICA;
            if (strcmp(lexema, "or")) return O_LOGICO;
            if (strcmp(lexema, "return")) return FUNCION_RETORNO;
            if (strcmp(lexema, "string")) return TIPO_CADENA;
            if (strcmp(lexema, "true")) return VERDADERO;
            if (strcmp(lexema, "var")) return VARIABLE;
            if (strcmp(lexema, "while")) return BUCLE_WHILE;
        }
        return IDENTIFICADOR;
    }

    /*
     * Caso 2:
     * Si el token comienza con un numero analizo lo siguiente:
     * Obtengo todos los digitos consecutivos posibles.
     * Si es que el caracter siguiente es un punto y lo que le sigue un numero, entonces obtengo el siguiente
     * numero entero posible y a esto lo convierto en mi numero real.
     * Sino retorno un numero entero.
     */

    if (isdigit(c)) {
        // Obtengo la parte entera
        pos = 0;
        do {
            lexema[pos++] = c;
            c = fgetc(arch);
        } while (isdigit(c));

        // Si es que tenemos un punto flotante analizamos dos casos
        if (c == '.') {
            int longitud_parte_entera = pos;
            do {
                lexema[pos++] = c;
                c = fgetc(arch);
            } while (isdigit(c));
            ungetc(c, arch);

            // Si es que no hemos encontrado ningun digito valido luego del punto, solo retornamos la parte entera
            if (pos == longitud_parte_entera + 1) {
                ungetc('.', arch);
                lexema[longitud_parte_entera] = '\0';
                return NUMERO_ENTERO;
            } else {
                // En otro caso, retorno el numero real que ha sido escaneado
                lexema[pos] = '\0';
                return NUMERO_REAL;
            }
        } else {
            // Si lo que sigue al punto no es lo suficiente como para formar la parte decimal
            // devuelvo el punto al buffer y retorno el numero entero
            ungetc(c, arch);
            lexema[pos] = '\0';
            return NUMERO_ENTERO;
        }
    }

    //En esta ultima parte, solo nos falta analizar simbolos.
    pos = 0;

    // Multiplicacion, potencia e multiplicacion directa
    if (c == '*') {
        c = fgetc(arch);
        if (c == '*') return OPERACION_POTENCIA;
        if (c == '=') return MULTIPLICACION_DIRECTA;
        /*
         * En caso no coincida con ninguna de las anteriores, unicamente estamos multiplicando y devolvemos
         * el ultimo caracter analizado al buffer del archivo.
         */
        ungetc(c, arch);
        return '*';
    }

    // Menor que, menor o igual que y left shift
    if (c == '<') {
        c = fgetc(arch);
        if (c == '<') return LEFT_SHIFT;
        if (c == '=') return MENOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return '<';
    }

    // Mayor que, mayor o igual que y right shift
    if (c == '>') {
        c = fgetc(arch);
        if (c == '>') return RIGHT_SHIFT;
        if (c == '=') return MAYOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return '>';
    }

    // Asignación, comparación de igualdad
    if (c == '=') {
        c = fgetc(arch);
        if (c == '=') return IGUALDAD;
        ungetc(c, arch);
        return '=';
    }

    if (c == '+') {
        c = fgetc(arch);
        if (c == '=') return INCREMENTO_DIRECTO;
        if (c == '+') return INCREMENTO_EN_UNIDAD;
        ungetc(c, arch);
        return '+';
    }

    if (c == '-') {
        c = fgetc(arch);
        if (c == '=') return DECREMENTO_DIRECTO;
        if (c == '-') return DECREMENTO_EN_UNIDAD;
        ungetc(c, arch);
        return '-';
    }

    if (c == '/') {
        c = fgetc(arch);
        if (c == '=') return DIVISION_DIRECTA;
        ungetc(c, arch);
        return '/';
    }

    if (c == '!') {
        c = fgetc(arch);
        if (c == '=') return DESIGUALDAD;
        ungetc(c, arch);
        return '!';
    }

    if (c == '&') {
        c = fgetc(arch);
        if (c == '&') return CONDICION_UNICA;
        ungetc(c, arch);
        return '&';
    }

    if (c == ';') return FIN_DE_INSTRUCCION;
    if (c == ',') return SEPARACION_VARIABLES;
    if (c == ':') return INICIO;
    if (c == '"') return INICIO_FIN_CADENA;
    if (c == '\'') return INICIO_FIN_CARACTER;
    if (c == '(') return PARENTESIS_IZQUIERDA;
    if (c == ')') return PARENTESIS_DERECHA;
    if (c == '[') return CORCHETE_IZQUIERDA;
    if (c == ']') return CORCHETE_DERECHA;
    if (c == '=') return ASIGNACION;

    if (c == '%') {
        c = fgetc(arch);
        if (c == '%') return INICIO_FIN_COMENTARIO_EN_BLOQUE;
        ungetc(c, arch);
        return COMENTARIO_EN_LINEA;
    }
    return c;
}