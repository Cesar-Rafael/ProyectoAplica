%{
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

// Prototipos de funcion
int yylex();
void yyerror(char *s);

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

char lexema[100];
FILE* arch;
%}

/***********************/
/* PALABRAS RESVADAS  */
/***********************/

// Instruccion "and"
%token Y_LOGICO

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

// Operacion "!"
%token NEGACION_LOGICA_2

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

%%

lista_instrucciones: lista_instrucciones instruccion  | instruccion  ;
instruccion:  expresion ';';

asignacion: IDENTIFICADOR '=' expresion;

/* and */
expresion: expresion Y_LOGICO term;

/* bool */
tipo_dato: TIPO_BOOLEAN asignacion;
tipo_dato: TIPO_BOOLEAN;

/* break */
expresion: BUCLE_SALIDA;

/* char */
tipo_dato: VARIABLE IDENTIFICADOR TIPO_CARACTER '=';

/* continue */
expresion: BUCLE_CONTINUACION;

/* double */
tipo_dato: TIPO_DOUBLE asignacion;
tipo_dato: TIPO_DOUBLE;

/* else */
expresion: CONDICION_SINO ':';

/* end */
expresion: FIN;

/* false */
expresion: FALSO;

/* for */
bucle_for: BUCLE_FOR '(' lista_instrucciones ')' ':' lista_instrucciones FIN;

/* function */
expresion: FUNCION_INICIO '('expresion')' ':';

/* if */
condicion_if: CONDICION_INICIO '(' expresion ')' ':' lista_instrucciones FIN | CONDICION_INICIO '(' expresion ')' ':' lista_instrucciones CONDICION_SINO ':' lista_instrucciones FIN;

/* input */
entrada: ENTRADA '(' IDENTIFICADOR ')';

/* int */
tipo_dato: TIPO_ENTERO asignacion;
tipo_dato: TIPO_ENTERO;

/* mod */
expresion: IDENTIFICADOR OPERACION_MODULAR IDENTIFICADOR;

/* not */
expresion: NEGACION_LOGICA term;

/* or */
expresion: expresion O_LOGICO term;

/* output */
salida: SALIDA '(' expresion ')';

/* return */
expresion: FUNCION_RETORNO expresion;

/* string */
tipo_dato: TIPO_CADENA asignacion;
tipo_dato: TIPO_CADENA

/* true */
true: VERDADERO;

/* var */
variable: VARIABLE IDENTIFICADOR tipo_dato;

/* while */
bucle_while: BUCLE_WHILE '(' expresion ')' ':';


/***********/
/* SIMBOLOS */
/***********/

/* OPERACION_SUMA */
expresion: expresion '+' term;

/* OPERACION_RESTA */
expresion: expresion '-' term;

/* OPERACION_MULTIPLICACION */
expresion: expresion '*' term;

/* OPERACION_DIVISION */
expresion: expresion '/' term;

/* OPERACION_POTENCIA */
expresion: expresion OPERACION_POTENCIA term;

/* DISYUNCION BINARIA */
expresion: expresion '|' term;

/* NEGACION_BINARIA */
expresion: '~' expresion;

/* CONJUNCION_BINARIA */
expresion: expresion '&' term;

/* NEGACION_LOGICA_2 */
expresion: '!' expresion;

/* LEFT_SHIFT */
expresion: expresion LEFT_SHIFT term;

/* RIGHT_SHIFT */
expresion: expresion RIGHT_SHIFT term;

/* DISYUNCION_EXCLUSIVA_BINARIA */
expresion: expresion '^' term;

/* FIN_DE_INSTRUCCION */
// Esto ya es cubierto por instruccion : expresion ';';

/* MENOR_QUE*/
expresion: expresion MENOR_QUE term;

/* MAYOR_QUE */
expresion: expresion MAYOR_QUE term;

/* MENOR_O_IGUAL_QUE */
expresion: expresion MENOR_O_IGUAL_QUE term;

/* MAYOR_O_IGUAL_QUE */
expresion: expresion MAYOR_O_IGUAL_QUE term;

/* COMENTARIO_EN_LINEA */
comentario_linea: '%' expresion '\n';

/* COMENTARIO_EN_BLOQUE */
comentario_bloque: INICIO_FIN_COMENTARIO_EN_BLOQUE expresion INICIO_FIN_COMENTARIO_EN_BLOQUE;

/* ASIGNACION */
asignacion: IDENTIFICADOR '=' expresion;

/* ASIGNACION_PROFUNDA */
asignacion_profunda: IDENTIFICADOR ASIGNACION_PROFUNDA expresion;

/* IGUALDAD */
igualdad: expresion IGUALDAD term;

/* DESIGUALDAD */
desigualdad: expresion DESIGUALDAD term;

/* INCREMENTO_EN_UNIDAD */
asignacion_incremento_en_unidad: IDENTIFICADOR INCREMENTO_EN_UNIDAD;

/* DECREMENTO_EN_UNIDAD */
asignacion_decremento_en_unidad: IDENTIFICADOR DECREMENTO_EN_UNIDAD;

/* CONDICION_UNICA */
expresion: expresion CONDICION_UNICA term;

/* INCREMENTO_DIRECTO */
asignacion_incremento: IDENTIFICADOR INCREMENTO_DIRECTO expresion;

/* DECREMENTO_DIRECTO */
asignacion_decremento: IDENTIFICADOR DECREMENTO_DIRECTO expresion;

/* MULTIPLICACION_DIRECTA */
asignacion_multiplicacion: IDENTIFICADOR MULTIPLICACION_DIRECTA expresion;

/* DIVISION_DIRECTA */
asignacion_division: IDENTIFICADOR DIVISION_DIRECTA expresion;

asignacion: IDENTIFICADOR '=' expresion;


expresion: expresion '+' term;

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