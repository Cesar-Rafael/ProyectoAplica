%{
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

#define MAX_SIZE 100

// Prototipos de funcion
int yylex(void);
void yyerror(char* s);

int GenerarCodigo(int op, int a1, int a2, int a3);
int GenerarTemporal(void);
void ImprimirTablaCodigos(void);
void ImprimirTablaSimbolos(void);
void InterpretarCodigo(void);
int LocalizarSimbolo(char* lexema, int token);

int cantidad_simbolos = 0;
int posicion_ultimo_codigo = -1;
int cantidad_variables_temporales = 1;
char lexema[MAX_SIZE];
FILE* arch;

typedef struct{
	int op;
	int a1;
	int a2;
	int a3;
} Codigo;

typedef struct{
	char nombre[MAX_SIZE];
	int token;
	int valor;
} Simbolo;

Codigo tabla_codigos[MAX_SIZE];
Simbolo tabla_simbolos[MAX_SIZE];

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

%}

/***********************/
/* PALABRAS RESERVADAS  */
/***********************/

// Instruccion "and"
%token Y_LOGICO

// Instruccion "bool"
%token TIPO_BOOLEAN

// Caracteres que no son utilizados para los identificadores, literales u otros tokens
%token CARACTER_RARO

// Intruccion "char"
%token TIPO_CARACTER

// Instruccion "continue"
%token BUCLE_CONTINUACION

// Instruccion "double"
%token TIPO_DOUBLE

// Instruccion "else"
%token CONDICION_SINO

// Instruccion "end"
%token FIN

// Instruccion "false"
%token FALSO

// Instruccion "for"
%token BUCLE_FOR

// Instruccion "function"
%token FUNCION_INICIO

// Instruccion "if"
%token CONDICION_INICIO

// Instruccion "input"
%token ENTRADA

// Instrucion "int"
%token TIPO_ENTERO

// Instruccion "mod"
%token OPERACION_MODULAR

// Instruccion "not"
%token NEGACION_LOGICA

// Instruccion "or"
%token O_LOGICO

// Instruccion "output"
%token SALIDA

// Instruccion "return"
%token FUNCION_RETORNO

// Instruccion "string"
%token TIPO_CADENA

// Instruccion "true"
%token VERDADERO

// Instruccion "var"
%token VARIABLE

// Instruccion "while"
%token BUCLE_WHILE

/************/
/* SIMBOLOS */
/***********/

// Operacion "+"
%token OPERACION_SUMA

// Operacion "-"
%token OPERACION_RESTA

// Operacion "*"
%token OPERACION_MULTIPLICACION

// Operacion "/"
%token OPERACION_DIVISION

// Operacion "**"
%token OPERACION_POTENCIA

// Operacion "|"
%token DISYUNCION_BINARIA

// Operacion "~"
%token NEGACION_BINARIA

// Operacion "&"
%token CONJUNCION_BINARIA

// Operacion "!"
//%token NEGACION_LOGICA_2

// Operacion "<<"
%token LEFT_SHIFT

// Operacion ">>"
%token RIGHT_SHIFT

// Operacion "^"
%token DISYUNCION_EXCLUSIVA_BINARIA

// Operacion ";"
%token FIN_DE_INSTRUCCION

// Operacion ","
%token SEPARACION_VARIABLES

// Operacion ":"
%token INICIO

// Contenedor """
%token INICIO_FIN_CADENA

// Contenedor "'"
%token INICIO_FIN_CARACTER

// Contenedor "("
%token PARENTESIS_IZQUIERDA

// Contenedor ")"
%token PARENTESIS_DERECHA

// Contenedor "["
%token CORCHETE_IZQUIERDA

// Contenedor "]"
%token CORCHETE_DERECHA

// Comparacion ">"
%token MENOR_QUE

// Comparacion ">"
%token MAYOR_QUE

// Comparacion "<="
%token MENOR_O_IGUAL_QUE

// Comparacion ">="
%token MAYOR_O_IGUAL_QUE

// Comentario en bloque "%%"
%token COMENTARIO

// Operacion "="
%token ASIGNACION

// Operacion ":="
%token ASIGNACION_PROFUNDA

// Operacion "=="
%token IGUALDAD

// Operacion "!="
%token DESIGUALDAD

// Operacion "++"
%token INCREMENTO_EN_UNIDAD

// Operacion "--"
%token DECREMENTO_EN_UNIDAD

// Operacion "&&"
%token CONDICION_UNICA

// Operacion "+="
%token INCREMENTO_DIRECTO

// Operacion "-="
%token DECREMENTO_DIRECTO

// Operacion "*="
%token MULTIPLICACION_DIRECTA

// Operacion "/="
%token DIVISION_DIRECTA

// Representacion de numero entero
%token NUMERO_ENTERO

// Representacion de numero real
%token NUMERO_REAL

// Identificador
%token IDENTIFICADOR

// Caracter '\n'
%token SALTO_LINEA

// Caracteres '->'
%token TERNARIO_SI

// Caracter '?'
%token TERNARIO_SINO

// Token que sera enviado para rellenar los parametros que no seran utilizados
%token NEUTRO

// Token para movernos a un determinado registro al obterner una condicion falsa
%token SALTAR_FALSO

// Token al cual siempre tendremos que saltar cuando es alcanzado
%token SALTAR_VERDADERO

%%

programa: lista_sentencias;

lista_sentencias: sentencia lista_sentencias
| ;

comentario: COMENTARIO lista_generica COMENTARIO;

lista_generica: elemento_generico lista_generica
| ;

elemento_generico:
Y_LOGICO
| TIPO_BOOLEAN
| TIPO_CARACTER
| BUCLE_CONTINUACION
| TIPO_DOUBLE
| CONDICION_SINO
| FIN
| FALSO
| BUCLE_FOR
| FUNCION_INICIO
| CONDICION_INICIO
| ENTRADA
| TIPO_ENTERO
| OPERACION_MODULAR
| NEGACION_LOGICA
| O_LOGICO
| SALIDA
| FUNCION_RETORNO
| TIPO_CADENA
| VERDADERO
| VARIABLE
| BUCLE_WHILE
| OPERACION_SUMA
| OPERACION_RESTA
| OPERACION_MULTIPLICACION
| OPERACION_DIVISION
| OPERACION_POTENCIA
| DISYUNCION_BINARIA
| NEGACION_BINARIA
| CONJUNCION_BINARIA
| LEFT_SHIFT
| RIGHT_SHIFT
| DISYUNCION_EXCLUSIVA_BINARIA
| FIN_DE_INSTRUCCION
| SEPARACION_VARIABLES
| INICIO
| INICIO_FIN_CADENA
| INICIO_FIN_CARACTER
| PARENTESIS_IZQUIERDA
| PARENTESIS_DERECHA
| CORCHETE_IZQUIERDA
| CORCHETE_DERECHA
| MENOR_QUE
| MAYOR_QUE
| MENOR_O_IGUAL_QUE
| MAYOR_O_IGUAL_QUE
| ASIGNACION
| ASIGNACION_PROFUNDA
| IGUALDAD
| DESIGUALDAD
| INCREMENTO_EN_UNIDAD
| DECREMENTO_EN_UNIDAD
| CONDICION_UNICA
| INCREMENTO_DIRECTO
| DECREMENTO_DIRECTO
| MULTIPLICACION_DIRECTA
| DIVISION_DIRECTA
| NUMERO_ENTERO
| NUMERO_REAL
| IDENTIFICADOR
| SALTO_LINEA
| TERNARIO_SI
| TERNARIO_SINO
| CARACTER_RARO;

sentencia: declaracion
| expresion_1 FIN_DE_INSTRUCCION
| impresion
| iteracion
| lectura
| seleccion
| asignacion
| operacion_unaria
| asignacion_operativa
| sentencia_condicional
| comentario;

impresion: SALIDA PARENTESIS_IZQUIERDA expresion_1 PARENTESIS_DERECHA FIN_DE_INSTRUCCION
{
	GenerarCodigo(SALIDA, $3, NEUTRO, NEUTRO);
};

lectura: ENTRADA PARENTESIS_IZQUIERDA IDENTIFICADOR PARENTESIS_DERECHA FIN_DE_INSTRUCCION
{
	GenerarCodigo(ENTRADA, $3, NEUTRO, NEUTRO);
};

iteracion: BUCLE_WHILE PARENTESIS_IZQUIERDA
{
	$$ = posicion_ultimo_codigo + 1;
} expresion_1 PARENTESIS_DERECHA
{
	GenerarCodigo(SALTAR_FALSO, $4, '?', NEUTRO);
	$$ = posicion_ultimo_codigo;
} bloque
{
	GenerarCodigo(SALTAR_VERDADERO, $3, NEUTRO, NEUTRO);
}
{
	tabla_codigos[$6].a2 = posicion_ultimo_codigo + 1;
};

seleccion:

CONDICION_INICIO
PARENTESIS_IZQUIERDA
expresion_1
PARENTESIS_DERECHA
INICIO
{
  GenerarCodigo(SALTAR_FALSO, $3, NEUTRO, NEUTRO);
  $$ = posicion_ultimo_codigo;
}
lista_sentencias
{
  GenerarCodigo(SALTAR_VERDADERO, NEUTRO, NEUTRO, NEUTRO);
  $$ = posicion_ultimo_codigo;
}
CONDICION_SINO
INICIO
{
  tabla_codigos[$6].a2 = posicion_ultimo_codigo + 1;
}
lista_sentencias
FIN
{
  tabla_codigos[$8].a1 = posicion_ultimo_codigo + 1;
}
;

bloque: INICIO lista_sentencias FIN
| sentencia ;

declaracion: VARIABLE IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
FIN_DE_INSTRUCCION;

declaracion: VARIABLE IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
ASIGNACION expresion_1
{
	GenerarCodigo(ASIGNACION, $3, $5, NEUTRO);
}
FIN_DE_INSTRUCCION;

asignacion: IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
ASIGNACION expresion_1
{
	GenerarCodigo(ASIGNACION, $2, $4, NEUTRO);
}
FIN_DE_INSTRUCCION;

operacion_unaria: IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} INCREMENTO_EN_UNIDAD FIN_DE_INSTRUCCION
{
	GenerarCodigo(INCREMENTO_EN_UNIDAD, $1, NEUTRO, NEUTRO);
} ;

operacion_unaria: IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} DECREMENTO_EN_UNIDAD FIN_DE_INSTRUCCION
{
	GenerarCodigo(DECREMENTO_EN_UNIDAD, $1, NEUTRO, NEUTRO);
} ;

/*
asignacion_operativa: IDENTIFICADOR asignacion_operativa_auxiliar;
asignacion_operativa_auxiliar: INCREMENTO_DIRECTO expresion_1 FIN_DE_INSTRUCCION
| DECREMENTO_DIRECTO expresion_1 FIN_DE_INSTRUCCION
| MULTIPLICACION_DIRECTA expresion_1 FIN_DE_INSTRUCCION
| DIVISION_DIRECTA expresion_1 FIN_DE_INSTRUCCION;
*/

asignacion_operativa:
IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} INCREMENTO_DIRECTO expresion_1 FIN_DE_INSTRUCCION
{
	GenerarCodigo(INCREMENTO_DIRECTO, $2, $4, NEUTRO);
	$$ = $2;
}
| IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} DECREMENTO_DIRECTO expresion_1 FIN_DE_INSTRUCCION
{
	GenerarCodigo(DECREMENTO_DIRECTO, $2, $4, NEUTRO);
	$$ = $2;
}
| IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} MULTIPLICACION_DIRECTA expresion_1 FIN_DE_INSTRUCCION
{
	GenerarCodigo(MULTIPLICACION_DIRECTA, $2, $4, NEUTRO);
	$$ = $2;
}
| IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
} DIVISION_DIRECTA expresion_1 FIN_DE_INSTRUCCION
{
	GenerarCodigo(DIVISION_DIRECTA, $2, $4, NEUTRO);
	$$ = $2;
} ;

expresion_1: expresion_1 MAYOR_QUE expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MAYOR_QUE, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_1 MENOR_QUE expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MENOR_QUE, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_1 MAYOR_O_IGUAL_QUE expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MAYOR_O_IGUAL_QUE, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_1 MENOR_O_IGUAL_QUE expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(MENOR_O_IGUAL_QUE, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_1 IGUALDAD expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(IGUALDAD, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_1 DESIGUALDAD expresion_2
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DESIGUALDAD, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_2
{
	$$ = $1;
};

expresion_2: expresion_2 OPERACION_SUMA expresion_3
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_SUMA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_2 OPERACION_RESTA expresion_3
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_RESTA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_2 DISYUNCION_BINARIA expresion_3
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DISYUNCION_BINARIA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_2 DISYUNCION_EXCLUSIVA_BINARIA expresion_3
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(DISYUNCION_EXCLUSIVA_BINARIA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_2 O_LOGICO expresion_3
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(O_LOGICO, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3
{
	$$ = $1;
};

expresion_3: expresion_3 OPERACION_MULTIPLICACION expresion_4
{
	int posicion_temporal = GenerarTemporal();
 	GenerarCodigo(OPERACION_MULTIPLICACION, posicion_temporal, $1, $3);
 	$$ = posicion_temporal;
}
| expresion_3 OPERACION_DIVISION expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_DIVISION, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3 OPERACION_MODULAR expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_MODULAR, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3 LEFT_SHIFT expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(LEFT_SHIFT, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3 RIGHT_SHIFT expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(RIGHT_SHIFT, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3 CONJUNCION_BINARIA expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(CONJUNCION_BINARIA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_3 Y_LOGICO expresion_4
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(Y_LOGICO, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| expresion_4
{
	$$=$1;
};

expresion_4: expresion_4 OPERACION_POTENCIA factor
{
	int posicion_temporal = GenerarTemporal();
	GenerarCodigo(OPERACION_POTENCIA, posicion_temporal, $1, $3);
	$$ = posicion_temporal;
}
| NEGACION_BINARIA factor
{
	int posicion_temporal = GenerarTemporal();
  	GenerarCodigo(NEGACION_BINARIA, posicion_temporal, $2, NEUTRO);
  	$$ = posicion_temporal;
}
| factor
{
	$$ = $1;
};

factor: terminal
{
	$$ = $1;
}
| PARENTESIS_IZQUIERDA expresion_1 PARENTESIS_DERECHA
{
	$$ = $2;
};

terminal: NUMERO_ENTERO
{
	$$ = LocalizarSimbolo(lexema, NUMERO_ENTERO);
}
| NUMERO_REAL
{
	$$ = LocalizarSimbolo(lexema, NUMERO_REAL);
}
| IDENTIFICADOR
{
	$$ = LocalizarSimbolo(lexema, IDENTIFICADOR);
}
| VERDADERO
{
	$$ = LocalizarSimbolo(lexema, VERDADERO);
}
| FALSO
{
	$$ = LocalizarSimbolo(lexema, FALSO);
};

sentencia_condicional: PARENTESIS_IZQUIERDA expresion_1 PARENTESIS_DERECHA CONDICION_UNICA
{
	GenerarCodigo(SALTAR_FALSO, $2, NEUTRO, NEUTRO);
	$$ = posicion_ultimo_codigo;
} sentencia
{
	tabla_codigos[$5].a2 = posicion_ultimo_codigo + 1;
};

%%

void InterpretarCodigo(void) {
	int op, a1, a2, a3;
	for (int i = 0; i <= posicion_ultimo_codigo; i++) {
		op = tabla_codigos[i].op;
		a1 = tabla_codigos[i].a1;
		a2 = tabla_codigos[i].a2;
		a3 = tabla_codigos[i].a3;

		if (op == ASIGNACION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor;
		}
		if (op == CONJUNCION_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor & tabla_simbolos[a3].valor;
		}
		if (op == DECREMENTO_DIRECTO) {
			tabla_simbolos[a1].valor -= tabla_simbolos[a2].valor;
		}
		if (op == DECREMENTO_EN_UNIDAD) {
			tabla_simbolos[a1].valor--;
		}
		if (op == DESIGUALDAD) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor != tabla_simbolos[a3].valor;
		}
		if (op == DISYUNCION_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor | tabla_simbolos[a3].valor;
		}
		if (op == DISYUNCION_EXCLUSIVA_BINARIA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor ^ tabla_simbolos[a3].valor;
		}
		if (op == DIVISION_DIRECTA) {
			tabla_simbolos[a1].valor /= tabla_simbolos[a2].valor;
		}
		if (op == ENTRADA) {
			scanf("%d", &tabla_simbolos[a1].valor);
		}
		if (op == IGUALDAD) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor == tabla_simbolos[a3].valor;
		}
		if (op == INCREMENTO_DIRECTO) {
			tabla_simbolos[a1].valor += tabla_simbolos[a2].valor;
		}
		if (op == INCREMENTO_EN_UNIDAD) {
			tabla_simbolos[a1].valor++;
		}
		if (op == LEFT_SHIFT) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor << tabla_simbolos[a3].valor;
		}
		if (op == MAYOR_O_IGUAL_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor >= tabla_simbolos[a3].valor;
		}
		if (op == MAYOR_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor > tabla_simbolos[a3].valor;
		}
		if (op == MENOR_O_IGUAL_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor <= tabla_simbolos[a3].valor;
		}
		if (op == MENOR_QUE) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor < tabla_simbolos[a3].valor;
		}
		if (op == MULTIPLICACION_DIRECTA) {
			tabla_simbolos[a1].valor *= tabla_simbolos[a2].valor;
		}
		if (op == NEGACION_BINARIA) {
			tabla_simbolos[a1].valor = ~tabla_simbolos[a2].valor;
		}
		if (op == NEGACION_LOGICA) {
			// TODO: Darle precedencia adecuada
		}
		if (op == O_LOGICO) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor || tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_DIVISION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor / tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_MODULAR) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor % tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_MULTIPLICACION) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor * tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_POTENCIA) {
			// En caso utilizar double, cambiamos el siguiente algoritmo por la funcion pow de math.h
			int base = tabla_simbolos[a2].valor;
			int exponente = tabla_simbolos[a3].valor;
			int resultado = 1;
			while (exponente > 0) {
				if (exponente & 1) resultado *= base;
				exponente >>= 1;
				base *= base;
			}
			tabla_simbolos[a1].valor = resultado;
		}
		if (op == OPERACION_RESTA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor - tabla_simbolos[a3].valor;
		}
		if (op == OPERACION_SUMA) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor + tabla_simbolos[a3].valor;
		}
		if (op == RIGHT_SHIFT) {
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor >> tabla_simbolos[a3].valor;
		}
		if (op == SALIDA) {
			printf("%d\n",tabla_simbolos[a1].valor);
		}
		if (op == SALTAR_FALSO) {
			if (!tabla_simbolos[a1].valor) i = a2 - 1;
		}
		if (op == SALTAR_VERDADERO) {
			i = a1 - 1;
		}
		if (op == Y_LOGICO) {
			// TODO: Darle precedencia adecuada
			tabla_simbolos[a1].valor = tabla_simbolos[a2].valor && tabla_simbolos[a3].valor;
		}
	}
}

int GenerarTemporal(void) {
	char t[10];
	sprintf(t, "tmp_%d", cantidad_variables_temporales++);
	return LocalizarSimbolo(t, IDENTIFICADOR);
}

int GenerarCodigo(int op, int a1, int a2, int a3) {
	posicion_ultimo_codigo++;
	tabla_codigos[posicion_ultimo_codigo].op = op;
	tabla_codigos[posicion_ultimo_codigo].a1 = a1;
	tabla_codigos[posicion_ultimo_codigo].a2 = a2;
	tabla_codigos[posicion_ultimo_codigo].a3 = a3;
}

void ImprimirTablaCodigos(void) {
	printf("Tabla Codigo:\n");
	printf("cod_op\tpos_sim\tpos_x\tpos_y\n");
	for (int pos = 0; pos <= posicion_ultimo_codigo; pos++) {
		printf("%d\t%d\t%d\t%d\n",
		tabla_codigos[pos].op,
		tabla_codigos[pos].a1,
		tabla_codigos[pos].a2,
		tabla_codigos[pos].a3);
	}
}

void ImprimirTablaSimbolos(void) {
	printf("Tabla Simbolos:\n");
	printf("pos \tnombre \ttoken \tvalor\n");
	for (int pos = 0; pos < cantidad_simbolos; pos++) {
		printf("%d\t%s\t%d\t%d\n",
		pos,
		tabla_simbolos[pos].nombre,
		tabla_simbolos[pos].token,
		tabla_simbolos[pos].valor);
	}
}

// Retorna la posicion del codigo buscado en caso exista, o del ultimo elemento en la tabla de simbolos pues este sera
// anadido en dicha posicion.

int LocalizarSimbolo(char* lexema, int token) {

	// Si el simbolo ya existe, retornamos su posicion en la tabla

  	for (int i = 0; i < cantidad_simbolos; i++) {
  		if (strcmp(tabla_simbolos[i].nombre, lexema) == 0) {
  			return i;
  		}
  	}

	// Asignamos un espacio en la tabla de simbolos al nuevo simbolo

	strcpy(tabla_simbolos[cantidad_simbolos].nombre, lexema);
	tabla_simbolos[cantidad_simbolos].token = token;
	if (token == NUMERO_ENTERO) {
		tabla_simbolos[cantidad_simbolos].valor = atoi(lexema);
	} else if (token == NUMERO_REAL) {
		tabla_simbolos[cantidad_simbolos].valor = atof(lexema);
	} else if (token == IDENTIFICADOR) {
		tabla_simbolos[cantidad_simbolos].valor = 0;
	}
	return cantidad_simbolos++;
}

int main(void) {
    // arch = fopen("../../tests/lab03/asignacion.raa", "r");
    // arch = fopen("../../tests/lab03/bucle_while.raa", "r");
    // arch = fopen("../../tests/lab03/comentarios.raa", "r");
    // arch = fopen("../../tests/lab03/entrada.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_aritmeticas.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_aritmeticas_no_triviales.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_binarias.raa", "r");
    // arch = fopen("../../tests/lab03/salida.raa", "r");
    // arch = fopen("../../tests/lab03/selectiva_if_else.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_unarias.raa", "r");
    // arch = fopen("../../tests/lab03/asignacion_operativa.raa", "r");
    // arch = fopen("../../tests/lab03/operadores_condicionales.raa", "r");
    // arch = fopen("../../tests/lab03/operaciones_booleanas.raa", "r");
    // arch = fopen("../../tests/lab03/sentencia_condicional.raa", "r");
    // arch = fopen("../../tests/lab03/operacion_ternaria.raa", "r");
    arch = fopen("../../tests/lab03/pruebas.raa", "r");

    if (arch == NULL) {
    	printf("ERROR: No se ha abierto el archivo test01.raa correctamente.\n");
        exit(1);
    }
    if (!yyparse()) {
        printf("Programa correcto.\n");
        ImprimirTablaSimbolos();
        ImprimirTablaCodigos();
        InterpretarCodigo();
        ImprimirTablaSimbolos();
    } else {
        printf("Error de sintaxis.\n");
    }
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yylex() {
    char c;
    int pos;
    while (isspace((c = fgetc(arch))));
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
            //printf("%c\n", c);
        } while ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9' || c == '_');
        ungetc(c, arch);
        lexema[pos++] = '\0';
        //printf("%s\n", lexema);
        int solo_alfabeto = 1;
        for (int i = 0; i < pos - 1; i++) {
            if (!isalpha(lexema[i])) {
                solo_alfabeto = 0;
                break;
            }
        }
        if (solo_alfabeto) {
            if (strcmp(lexema, "and") == 0) return Y_LOGICO;
            if (strcmp(lexema, "bool") == 0) return TIPO_BOOLEAN;
            if (strcmp(lexema, "char") == 0) return TIPO_CARACTER;
            if (strcmp(lexema, "continue") == 0) return BUCLE_CONTINUACION;
            if (strcmp(lexema, "double") == 0) return TIPO_DOUBLE;
            if (strcmp(lexema, "else") == 0) return CONDICION_SINO;
            if (strcmp(lexema, "end") == 0) return FIN;
            if (strcmp(lexema, "false") == 0) return FALSO;
            if (strcmp(lexema, "for") == 0) return BUCLE_FOR;
            if (strcmp(lexema, "function") == 0) return FUNCION_INICIO;
            if (strcmp(lexema, "if") == 0) return CONDICION_INICIO;
            if (strcmp(lexema, "input") == 0) return ENTRADA;
            if (strcmp(lexema, "int") == 0) return TIPO_ENTERO;
            if (strcmp(lexema, "mod") == 0) return OPERACION_MODULAR;
            if (strcmp(lexema, "not") == 0) return NEGACION_LOGICA;
            if (strcmp(lexema, "or") == 0) return O_LOGICO;
            if (strcmp(lexema, "output") == 0) return SALIDA;
            if (strcmp(lexema, "return") == 0) return FUNCION_RETORNO;
            if (strcmp(lexema, "string") == 0) return TIPO_CADENA;
            if (strcmp(lexema, "true") == 0) return VERDADERO;
            if (strcmp(lexema, "var") == 0) return VARIABLE;
            if (strcmp(lexema, "while") == 0) return BUCLE_WHILE;
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
        return OPERACION_MULTIPLICACION;
    }

    // Menor que, menor o igual que y left shift
    if (c == '<') {
        c = fgetc(arch);
        if (c == '<') return LEFT_SHIFT;
        if (c == '=') return MENOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return MENOR_QUE;
    }

    // Mayor que, mayor o igual que y right shift
    if (c == '>') {
        c = fgetc(arch);
        if (c == '>') return RIGHT_SHIFT;
        if (c == '=') return MAYOR_O_IGUAL_QUE;
        ungetc(c, arch);
        return MAYOR_QUE;
    }

    // Asignación, comparación de igualdad
    if (c == '=') {
        c = fgetc(arch);
        if (c == '=') return IGUALDAD;
        ungetc(c, arch);
        return ASIGNACION;
    }

    if (c == '+') {
        c = fgetc(arch);
        if (c == '=') return INCREMENTO_DIRECTO;
        if (c == '+') return INCREMENTO_EN_UNIDAD;
        ungetc(c, arch);
        return OPERACION_SUMA;
    }

    if (c == '-') {
        c = fgetc(arch);
        if (c == '=') return DECREMENTO_DIRECTO;
        if (c == '-') return DECREMENTO_EN_UNIDAD;
        if (c == '>') return TERNARIO_SI;
        ungetc(c, arch);
        return OPERACION_RESTA;
    }

    if (c == '/') {
        c = fgetc(arch);
        if (c == '=') return DIVISION_DIRECTA;
        ungetc(c, arch);
        return OPERACION_DIVISION;
    }

    if (c == '!') {
        c = fgetc(arch);
        if (c == '=') return DESIGUALDAD;
        ungetc(c, arch);
        return NEGACION_LOGICA;
    }

    if (c == '&') {
			c = fgetc(arch);
			if (c == '&') return CONDICION_UNICA;
			ungetc(c, arch);
			return CONJUNCION_BINARIA;
    }

    if (c == '%'){
    	c = fgetc(arch);
    	if (c == '%') return COMENTARIO;
    	ungetc(c, arch);
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
    if (c == '~') return NEGACION_BINARIA;
    if (c == '|') return DISYUNCION_BINARIA;
    if (c == '^') return DISYUNCION_EXCLUSIVA_BINARIA;
    if (c == '?') return TERNARIO_SINO;

    return CARACTER_RARO;
}
