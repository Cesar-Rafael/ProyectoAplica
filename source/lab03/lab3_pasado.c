lista_instrucciones: lista_instrucciones instruccion  | instruccion  ;
instruccion:  expresion ';';

asignacion: IDENTIFICADOR '=' expresion;

/* and */
expresion: expresion Y_LOGICO expresion;

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
expresion: NEGACION_LOGICA expresion;

/* or */
expresion: expresion O_LOGICO expresion;

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
expresion: expresion '+' expresion;

/* OPERACION_RESTA */
expresion: expresion '-' expresion;

/* OPERACION_MULTIPLICACION */
expresion: expresion '*' expresion;

/* OPERACION_DIVISION */
expresion: expresion '/' expresion;

/* OPERACION_POTENCIA */
expresion: expresion OPERACION_POTENCIA expresion;

/* DISYUNCION BINARIA */
expresion: expresion '|' expresion;

/* NEGACION_BINARIA */
expresion: '~' expresion;

/* CONJUNCION_BINARIA */
expresion: expresion '&' expresion;

/* NEGACION_LOGICA_2 */
expresion: '!' expresion;

/* LEFT_SHIFT */
expresion: expresion LEFT_SHIFT expresion;

/* RIGHT_SHIFT */
expresion: expresion RIGHT_SHIFT expresion;

/* DISYUNCION_EXCLUSIVA_BINARIA */
expresion: expresion '^' expresion;

/* FIN_DE_INSTRUCCION */
// Esto ya es cubierto por instruccion : expresion ';';

/* MENOR_QUE*/
expresion: expresion MENOR_QUE expresion;

/* MAYOR_QUE */
expresion: expresion MAYOR_QUE expresion;

/* MENOR_O_IGUAL_QUE */
expresion: expresion MENOR_O_IGUAL_QUE expresion;

/* MAYOR_O_IGUAL_QUE */
expresion: expresion MAYOR_O_IGUAL_QUE expresion;

/* COMENTARIO_EN_LINEA */
comentario_linea: '%' expresion '\n';

/* COMENTARIO_EN_BLOQUE */
comentario_bloque: INICIO_FIN_COMENTARIO_EN_BLOQUE expresion INICIO_FIN_COMENTARIO_EN_BLOQUE;

/* ASIGNACION */
asignacion: IDENTIFICADOR '=' expresion;

/* ASIGNACION_PROFUNDA */
asignacion_profunda: IDENTIFICADOR ASIGNACION_PROFUNDA expresion;

/* IGUALDAD */
igualdad: expresion IGUALDAD expresion;

/* DESIGUALDAD */
desigualdad: expresion DESIGUALDAD expresion;

/* INCREMENTO_EN_UNIDAD */
asignacion_incremento_en_unidad: IDENTIFICADOR INCREMENTO_EN_UNIDAD;

/* DECREMENTO_EN_UNIDAD */
asignacion_decremento_en_unidad: IDENTIFICADOR DECREMENTO_EN_UNIDAD;

/* CONDICION_UNICA */
expresion: expresion CONDICION_UNICA expresion;

/* INCREMENTO_DIRECTO */
asignacion_incremento: IDENTIFICADOR INCREMENTO_DIRECTO expresion;

/* DECREMENTO_DIRECTO */
asignacion_decremento: IDENTIFICADOR DECREMENTO_DIRECTO expresion;

/* MULTIPLICACION_DIRECTA */
asignacion_multiplicacion: IDENTIFICADOR MULTIPLICACION_DIRECTA expresion;

/* DIVISION_DIRECTA */
asignacion_division: IDENTIFICADOR DIVISION_DIRECTA expresion;

asignacion: IDENTIFICADOR '=' expresion;
