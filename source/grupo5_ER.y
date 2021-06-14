%{
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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

command: expr {printf("%d\n",$1);} ;
expr: expr '+' term { $$=$1+$3; };
expr: expr '-' term { $$=$1-$3; };
term: term '*' fact { $$=$1*$3; };
term: term '/' fact { $$=$1/$3; };

term: term OPERACION_POTENCIA fact { $$=pow($1,$3); };
term: term LEFT_SHIFT fact { $$=$1<<$3; };
term: term RIGHT_SHIFT fact { $$=$1>>$3; };
term: term '&' fact { $$=$1&$3; };
term: term '^' fact { $$=$1^$3; };
term: term '|' fact { $$=$1|$3; };
expr: term  { $$=$1;};

term: fact { $$=$1; };
term: '~'fact { $$=~$2; };
term: term '=' fact { $1=$3; };
fact: NUMERO_ENTERO { $$=$1; };
fact:'(' expr ')' { $$=$2; };

%%
/* 
las expresiones de un caracter no son necesarias colocarlas en el while, es decir
no se coloca su return, se puede hacer de frente en la expresión de arriba

Borradores:
----------


*/
int main(void) {
	arch = fopen("Ejemplo.txt", "r");
	if(arch == NULL){
		printf("ERROR: No se ha abierto el archivo Ejemplo.txt correctamente.\n");
		exit(1);
	}
	if (!yyparse()) {
		printf("Cadena valida\n");
	} else {
		printf("Cadena invalida\n");
	}
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}

int yylex() {
	char c;
	int i;
	while (!feof(arch)) {
		c = fgetc(arch);
		if (c =='\n') continue;
		if (c == EOF) return c;
		if (isspace(c)) continue;
		if (isalpha(c)){
			i = 0;
			do {
				lexema[i++] = c;
				//printf("Lexema = %s\n", lexema);
				c = fgetc(arch);
				//printf("Hola\n");
			} while(isalnum(c));
			ungetc(c, arch);
			lexema[i++] = '\0';
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
		if (isdigit(c)) {
			//scanf("%d",&yylval);
			i = 0;
			do {
				lexema[i++] = c;
				c = fgetc(arch);
			} while(isdigit(c));
			ungetc(c, arch);
			lexema[i++] = '\0';
			yylval = atoi(lexema); // Apilo el valor del lexema
			return NUMERO_ENTERO;
		}
		// Tenemos que hacerlo de esta manera
		i = 0;
		if (c == '*') {
			lexema[i++] = '*';
			c = fgetc(arch);
			if(c == '*'){
				lexema[i++] = '*';
				lexema[i] = '\0';
				return OPERACION_POTENCIA;
			}
			if(c == '='){
				lexema[i++] = '=';
				lexema[i] = '\0';
				return MULTIPLICACION_DIRECTA;
			}
			ungetc(c, arch); // devolvemos el caracter si no es OPERACION_POTENCIA ni MULTIPLICACION_DIRECTA
		}
		if(c == '<'){
			lexema[i++] = '<';
			c = fgetc(arch);
			if(c == '<'){
				lexema[i++] = '<';
				lexema[i] = '\0';
				return LEFT_SHIFT;
			}
			if(c == '='){
				lexema[i++] = '=';
				lexema[i] = '\0';
				return MENOR_O_IGUAL_QUE;
			}
			ungetc(c, arch); // devolvemos el caracter si no es LEFT_SHIFT ni MENOR_O_IGUAL_QUE
		}

		if(c == '>'){
			lexema[i++] = '>';
			c = fgetc(arch);
			if(c == '>'){
				lexema[i++] = '>';
				lexema[i] = '\0';
				return RIGHT_SHIFT;
			}
			if(c == '='){
				lexema[i++] = '=';
				lexema[i] = '\0';
				return MAYOR_O_IGUAL_QUE;
			} 
			ungetc(c, arch); // devolvemos el caracter si no es RIGHT_SHIFT ni MAYOR_O_IGUAL_QUE
		}
	// Ver si existe el signo de exclamación ! en la lista de operadores 
		/*
		if (strcmp(lexema, "**")) return OPERACION_POTENCIA;
		if (strcmp(lexema, "<<")) return LEFT_SHIFT;
		if (strcmp(lexema, ">>")) return RIGHT_SHIFT;
		if (strcmp(lexema, "<=")) return MENOR_O_IGUAL_QUE;
		if (strcmp(lexema, ">=")) return MAYOR_O_IGUAL_QUE;
		if (strcmp(lexema, "%%")) return INICIO_FIN_COMENTARIO_EN_BLOQUE; // Corregir
		if (strcmp(lexema, "==")) return IGUALDAD;
		if (strcmp(lexema, "!=")) return DESIGUALDAD;
		if (strcmp(lexema, "++")) return INCREMENTO_EN_UNIDAD;
		if (strcmp(lexema, "--")) return DECREMENTO_EN_UNIDAD;
		if (strcmp(lexema, "&&")) return CONDICION_UNICA;
		if (strcmp(lexema, "+=")) return INCREMENTO_DIRECTO;
		if (strcmp(lexema, "-=")) return DECREMENTO_DIRECTO;
		if (strcmp(lexema, "*=")) return MULTIPLICACION_DIRECTA;
		if (strcmp(lexema, "/=")) return DIVISION_DIRECTA;	
		*/	
/*
		// Estos ya están listos
		if (c == '+') return OPERACION_SUMA; 
		if (c == '-') return OPERACION_RESTA;
		if (c == '*') return OPERACION_MULTIPLICACION;
		if (c == '/') return OPERACION_DIVISION;
		if (c == '|') return DISYUNCION_BINARIA;
		if (c == '~') return NEGACION_BINARIA;
		if (c == '&') return CONJUNCION_BINARIA;
		if (c == '^') return DISYUNCION_EXCLUSIVA_BINARIA;

		// Estos faltan :'v
		if (c == ';') return FIN_DE_INSTRUCCION;
		if (c == ',') return SEPARACION_VARIABLES;
		if (c == ':') return INICIO;
		if (c == '"') return INICIO_FIN_CADENA;
		if (c == 39) return INICIO_FIN_CARACTER; // Impresión de una comilla simple
		if (c == '(') return PARENTESIS_IZQUIERDA;
		if (c == ')') return PARENTESIS_DERECHA;
		if (c == '[') return CORCHETE_IZQUIERDA;
		if (c == ']') return CORCHETE_DERECHA;
		if (c == '=') return ASIGNACION;
		if (c == '<') return MENOR_QUE;
		if (c == '>') return MAYOR_QUE;
		if (c == '%') return COMENTARIO_EN_LINEA;
*/
		return c;
	}
}