%%
  /***********************/
  /* PALABRAS RESERVADAS */
  /***********************/

and { printf("Y_LOGICO "); }

bool { printf("TIPO_BOOLEAN "); }

break { printf("BUCLE_SALIDA "); }

char { printf("TIPO_CARACTER "); }

continue { printf("BUCLE_CONTINUACION "); }

double { printf("TIPO_DOUBLE "); }

else { printf("CONDICION_SINO "); }
end { printf("FIN "); }

false { printf("FALSO "); }

for { printf("BUCLE_FOR "); }

function { printf("FUNCION_INICIO "); }

if { printf("CONDICION_INICIO "); }

input { printf("ENTRADA "); }

int { printf("TIPO_ENTERO "); }

mod { printf("OPERACION_MODULAR "); }

not { printf("NEGACION_LOGICA "); }

or { printf("O_LOGICO "); }

output { printf("SALIDA "); }

return { printf("FUNCION_RETORNO "); }

string { printf("TIPO_CADENA "); }

true { printf("VERDADERO ");}

var { printf("VARIABLE "); }

while { printf("BUCLE_WHILE "); }

  /************/
  /* SIMBOLOS */
  /************/

"+" { printf("OPERACION_SUMA "); }

"-" { printf("OPERACION_RESTA "); }

"*" { printf("OPERACION_MULTIPLICACION "); }

"/" { printf("OPERACION_DIVISION "); }

"**" { printf("OPERACION_POTENCIA "); }

"|" { printf("DISYUNCION_BINARIA "); }

"~" { printf("NEGACION_BINARIA "); }

"&" { printf("CONJUNCION_BINARIA "); }
"^" { printf("DISYUNCION_EXCLUSIVA_BINARIA "); }

";" { printf("FIN_DE_INSTRUCCION "); }

"," { printf("SEPARACION_VARIABLES "); }

":" { printf("INICIO "); }

"\"" { printf("INICIO_FIN_CADENA "); }

"'" { printf("INICIO_FIN_CARACTER "); }

"(" { printf("PARENTESIS_IZQUIERDA "); }

")" { printf("PARENTESIS_DERECHA "); }

"[" { printf("CORCHETE_IZQUIERDA "); }

"]" { printf("CORCHETE_DERECHA "); }

"<" { printf("MENOR_QUE "); }

">" { printf("MAYOR_QUE "); }
"=" { printf("ASIGNACION "); }
"<=" { printf("MENOR_O_IGUAL_QUE "); }

">=" { printf("MAYOR_O_IGUAL_QUE "); }

"\%" { printf("COMENTARIO_EN_LINEA "); }

"\%\%" { printf("INICIO_FIN_COMENTARIO_EN_BLOQUE "); }

"=" { printf("ASIGNACION "); }

":=" { printf("ASIGNACION_PROFUNDA "); }

"==" { printf("IGUALDAD "); }

"!=" { printf("DESIGUALDAD "); }

"++" { printf("INCREMENTO_EN_UNIDAD "); }

"--" { printf("DECREMENTO_EN_UNIDAD "); }

"&&" { printf("CONDICION_UNICA "); }

"+=" { printf("INCREMENTO_DIRECTO "); }

"-=" { printf("DECREMENTO_DIRECTO "); }

"*=" { printf("MULTIPLICACION_DIRECTA "); }

"/=" { printf("DIVISION_DIRECTA "); }

  /*****************/
  /* ALFANUMERICOS */
  /*****************/

[0-9]+ { printf("NUMERO_ENTERO "); }
[A-Za-z*&#_]* { printf("IDENTIFICADOR "); }

%%