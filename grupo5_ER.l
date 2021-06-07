%%
    /* PALABRAS RESERVADAS */
whether { printf("CONDICION_INICIO "); }
else { printf("CONDICION_SINO "); }
end { printf("FIN "); }
while { printf("BUCLE_WHILE "); }
for { printf("BUCLE_FOR "); }
break { printf("BUCLE_SALIDA "); }
continue { printf("BUCLE_CONTINUACION "); }
function { printf("FUNCION_INICIO "); }
return { printf("FUNCION_RETORNO "); }
input { printf("ENTRADA "); }
output { printf("SALIDA "); }
var { printf("VARIABLE "); }
int { printf("TIPO_ENTERO "); }
char { printf("TIPO_CARACTER "); }
string { printf("TIPO_CADENA "); }
    /* SIMBOLOS */
"+" { printf("OPERACION_SUMA "); }
"-" { printf("OPERACION_RESTA "); }
"*" { printf("OPERACION_MULTIPLICION "); }
"/" { printf("OPERACION_DIVISION "); }
mod { printf("OPERACION_MODULAR "); }
"**" { printf("OPERACION_POTENCIA "); }
"|" { printf("DISYUNCION_BINARIA "); }
"~" { printf("NEGACION_BINARIA "); }
"&" { printf("CONJUNCION_BINARIA "); }
"^" { printf("DISYUNCION_EXCLUSIVA_BINARIA "); }
";" { printf("FIN_DE_INSTRUCCION "); }
"," { printf("SEPARACION_VARIABLES "); }

"\"" {printf("INICIO_FIN_CADENA ")}
"'" {printf("INICIO_FIN_CARACTER ")}
"(" {printf("")}

%%