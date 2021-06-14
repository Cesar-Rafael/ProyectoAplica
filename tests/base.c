#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*prototipos de funcion*/
int yylex();

void yyerror(char *s);

/*estructuras*/
char lexema[100];

int main(void) {
    if (!yyparse()) {
        printf("Cadena valida\n");
    } else {
        printf("Cadena invalida\n");
    }
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yylex(void) {
    char chr;
    int pos;
    while (!feof(arch)) {
        c = fgetc(arch);
        if (c == '\n') continue;
        if (c == EOF) return c;
        if (isspace(c)) continue;
        if (isalpha(c)) {
            i = 0;
            do {
                lexema[i++] = c;
                c = fgetc(arch);
            } while (isalnum(c));
            ungetc(c, arch);
            lexema[i++] = '\0';
            if (!strcmp(lexema, "if")) return SI; /*espalreservada*/
            else if (strcmp(lexema, "and")) return Y_LOGICO;
            else if (strcmp(lexema, "bool")) return TIPO_BOOLEAN;

            return ID;

        }
        if (isdigit(c)) {
            //scanf("%d",&yylval);
            i = 0;
            do {
                lexema[i++] = c;
                c = fgetc(arch);
            } while (isdigit(c));
            ungetc(c, arch);
            lexema[i++] = '\0';
            return NUMBER;
        }

        if (c == '+') return OPERACION_SUMA;
        if (c == '-') return OPERACION_RESTA;
        if (c == '*') return OPERACION_MULTIPLICACION;
        if (c == '/') return OPERACION_DIVISION;
        if (c == '**') return OPERACION_POTENCIA;
        if (c == '|') return DISYUNCION_BINARIA;
        if (c == '~') return NEGACION_BINARIA;
        if (c == '&') return CONJUNCION_BINARIA;
        if (c == '^') return DISYUNCION_EXCLUSIVA_BINARIA;





        return c;
    }
}