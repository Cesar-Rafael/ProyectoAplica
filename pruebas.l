< {printf("MENOR A");}
> {printf("MAYOR A");}
<= {printf("MENOR O IGUAL A");}
>= {printf("MAYOR O IGUAL A");}

0+|1+|2+|3+|4+|5+|6+|7+|8+|9+ {printf("NUMERO ENTERO");}

if (condicion) {
    int x = 69;
    cout << x << endl;
} else {
    int y = 68;
    cout << y << endl;
}

if (condicion) :
    int x = 69;
    cout << x << endl;

end

if (condicion) :
    int x = 69;
    cout << xd << endl;
end


int main(){

    int n ;

    n= 1;

}

y en respuesta tendría los siguientes tokens:

TIPO_ENTERO PRINCIPAL PARIZQ PARDER LLAVEIZQ TIPO_ENTERO IDENTIFICADOR PUNTOCOMA IDENTIFICADOR IGUAL NUMERO_ENTERO LLAVEDER

[0-9]+ {printf("NUMERO ENTERO ");}
([a-z]|[A-Z])+ {printf("IDENTIFICADOR ");}
var {printf("DECLARACION_VARIABLE ");}
int {printf("TIPO_ENTERO ");}
break ;


(<) {printf("MENOR A ");}
(>) {printf("MAYOR A ");}
(<=) {printf("MENOR O IGUAL A ");}
(>=) {printf("MAYOR O IGUAL A ");}


(+) { printf("OPERACION_MAS "); }
(-) { printf("OPERACION_MENOS "); }
(*) { printf("OPERACION_MAS "); }