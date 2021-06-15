%{
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
/* Prototipos de funcion */
int yylex();
void yyerror(char *s);

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

/*estructuras*/
char lexema[100];
FILE * arch;

%}

/***********************/
/* PALABRAS RESVADAS  */
/***********************/

// Instruccion "and"
%token Y_LOGIC

// Instruccion "bool"
%token TIPO_BOOLEAN

// Instruccion "break"
%token BUCLE_SALIDA

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

// Operacion """
%token INICIO_FIN_CADENA


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

// Comentario en linea "%"
%token COMENTARIO_EN_LINEA

// Comentario en bloque "%%"
%token INICIO_FIN_COMENTARIO_EN_BLOQUE

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

//Punto
//%token PUNTO TODO: Manuel confirmas

%%

listainst: listainst instr  | instr  ;
instr :  asignacion ';'
asignacion: IDENTIFICADOR '=' expression;
expression: expression '+' term { $$ = $1 + $3; };

expresion: expresion '-' term { $$ = $1 - $3; };
term: term '*' fact { $$ = $1 * $3; };
term: term '/' fact { $$ = $1 / $3; };

term: term OPERACION_POTENCIA fact { $$=pow($1,$3); };
term: term LEFT_SHIFT fact { $$=$1<<$3; };
term: term RIGHT_SHIFT fact { $$=$1>>$3; };
term: term '&' fact { $$ = $1 & $3; };
term: term '^' fact { $$ = $1 ^ $3; };
term: term '|' fact { $$ = $1 | $3; };
expresion: term  { $$ = $1;};

term: fact { $$ = $1; };
term: '~'fact { $$ = ~$2; };
term: term '=' fact { $1 = $3; };
fact: NUMERO_ENTERO { $$ = $1; };
fact: '(' expresion ')' { $$ = $2; };

%%