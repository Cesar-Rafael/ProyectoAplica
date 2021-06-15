int main(void) {
    arch = fopen("Ejemplo.txt", "r");
    if (arch == NULL) {
        printf("ERROR: No se ha abierto el archivo Ejemplo.txt correctamente.\n");
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

    while (!feof(arch)) {
        c = fgetc(arch);
        if (c == '\n') continue;
        if (c == EOF) return c;
        if (isspace(c)) continue;
        /*
         * Caso 1:
         * Si el token comienza con una letra del alfabeto tenemos las siguientes posibilidades:
         * - Todas son letras del alfabeto. Verifico si es que es palabra reservada para retornarla.
         * - En otro caso, necesariamente es un identificador
         *
         */
        if (isalpha(c)) {
        }
        if (EsBuenCaracter(c)) {
            pos = 0;
            do {
                lexema[pos++] = c;
                c = fgetc(arch);
            } while (EsBuenCaracter(c));
            ungetc(c, arch);
            lexema[pos++] = '\0';
            /*
             * Primero, analizamos si todos los caracteres son del alfabeto. En caso todos sus caracteres sean palabras
             * del alfabeto, retornaremos si es una palabra reservada. En caso no lo sea, devolveremos que es un
             * identificador;
             */
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
                return IDENTIFICADOR;
            }

            /*
             * Segundo, verificaremos si el sujeto es unicamente un numero.
             * El caso problematico es cuando es posiblemente un double. Por lo que analizaremos que el que sigue es un
             * punto. En caso esto sea cierto, analizaremos si lo que sigues es de nuevo unicamente un entero y que luego
             * no haya un punto. Sino, el numero es un numero
             */

            int solo_numero = 1;
            for (int i = 0; i < pos - 1; i++) {
                if (!isdigit(lexema[i])) {
                    solo_numero = 0;
                    break;
                }
            }

            if (solo_numero) {
                // Caso 1: Estamos frente a un double
                c = fgetc(arch);
                if (c == '.') {
                    // Reemplazo el fin de cadena por el punto flotante
                    lexema[pos - 1] = '.';
                    int inicio_parte_decimal = pos;
                    // Leo el siguiente token
                    do {
                        lexema[pos++] = c;
                        c = fgetc(arch);
                    } while (EsBuenCaracter(c));
                    ungetc(c, arch);
                    lexema[pos++] = '\0';
                    if (inicio_parte_decimal < pos - 1) {
                        solo_numero = 1;
                        for (int i = inicio_parte_decimal; i < pos - 1; i++) {
                            if (!isdigit(lexema[i])) {
                                solo_numero = 0;
                                break;
                            }
                        }
                        if (solo_numero) return NUMERO_REAL;
                        // TODO: Preguntar a Layla que debo retornar ene ste caso
                    } else {
                        // TODO: Preguntar a Layla que hacer en este caso
                    }
                } else {
                    // Caso 2: Estamos frente a un numero entero
                    // Primero devolvemos el caracter extraido que no coincidio con el punto flotante
                    unget(c, arch);
                    return NUMERO_ENTERO;
                }
            }

            /*
             * Cuando hemos llegado hasta este lugar, todos los caracteres que tenemos son validos para un identificador.
             * Simplemente nos queda verificar que no comience con un numero.
             */
            // TODO: Consultar  a Layla sobre que retornar cuando algo no es valido
            assert(!isdigit(lexema[0]));
            return IDENTIFICADOR;
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
        if(c == '<')
            c = fgetc(arch);
            if(c == '<') return LEFT_SHIFT;
            if(c == '=') return MENOR_O_IGUAL_QUE;
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
            if (c == '=') return SUMA;
            ungetc(c, arch);
            return '=';
        }
        if(c == '-') {
            c = fgetc(arch);
            if (c == '=') return DECREMENTO_DIRECTO;
            if (c == '-') return DECREMETO_EN_UNIDAD;
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


        //if (strcmp(lexema, "%%")) return INICIO_FIN_COMENTARIO_EN_BLOQUE; // Corregir
        //if (strcmp(lexema, "==")) return IGUALDAD;
        //if (strcmp(lexema, "!=")) return DESIGUALDAD; // PILI
        //if (strcmp(lexema, "++")) return INCREMENTO_EN_UNIDAD; // F
        //if (strcmp(lexema, "--")) return DECREMENTO_EN_UNIDAD;// F
        //if (strcmp(lexema, "&&")) return CONDICION_UNICA; // P
        //if (strcmp(lexema, "+=")) return INCREMENTO_DIRECTO;
        //if (strcmp(lexema, "-=")) return DECREMENTO_DIRECTO;
        //if (strcmp(lexema, "/=")) return DIVISION_DIRECTA; // P

        /*
         * Estos ya están listos
        if (c == '+') return OPERACION_SUMA;
        if (c == '-') return OPERACION_RESTA;
        if (c == '/') return OPERACION_DIVISION;
        if (c == '|') return DISYUNCION_BINARIA;
        if (c == '~') return NEGACION_BINARIA;
        if (c == '&') return CONJUNCION_BINARIA;
        if (c == '^') return DISYUNCION_EXCLUSIVA_BINARIA;
         *
         */

        if (c == ';') return FIN_DE_INSTRUCCION;
        if (c == ',') return SEPARACION_VARIABLES;
        if (c == ':') return INICIO;
        if (c == '"') return INICIO_FIN_CADENA;
        if (c == 39) return INICIO_FIN_CARACTER; // Comilla simple
        if (c == '(') return PARENTESIS_IZQUIERDA;
        if (c == ')') return PARENTESIS_DERECHA;
        if (c == '[') return CORCHETE_IZQUIERDA;
        if (c == ']') return CORCHETE_DERECHA;
        if (c == '=') return ASIGNACION;
        if (c == '%') return COMENTARIO_EN_LINEA;

        // ENTERO IDENTIFICARDOR ASIGNACION NUMERO COMA
        // COMENTARIO IDENTIFICADOR ASIGNIACION NUMERO
        // Comentario en linea
        pos = 0;
        if (c == '%') {
            c = fgetc(arch);
            if (c == '%'){ //inicio del bloque de comentario
                while (1) {
                    c = fgetc(arch);
                    if (c == '%') {
                        c = fgetc(arch);
                        if (c == '%') //deben haber %% para que sea el fin del comentario
                            break;
                        lexema[pos++] = '%'; //puede que un % sea parte del comentario
                        lexema[pos++] = c;
                    }
                    else {
                        lexema[pos++] = c;
                    }
                }
                lexema[pos] = '\0';
                return COMENTARIO_EN_BLOQUE;
            }
            else {
                while (1) {
                    c = fgetc(arch);
                    if (c == '\n') break;
                    lexema[pos++] = c;
                }
                lexema[pos]='\0';
                return COMENTARIO_EN_LINEA;
            }
        }
        return c;
    }
}