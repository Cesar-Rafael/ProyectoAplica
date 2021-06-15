
int EsBuenCaracter(char c) {
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' && '0' <= c || c <= '9' || c == '_';
}

int yylex() {
    char c;
    int pos;
    while (isspace((c = fgetc(arch))) continue;
    if (c == '\n') return c;
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
        } while (EsBuenCaracter(c));
        ungetc(c, arch);
        lexema[pos++] = '\0';
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
        return '*';
    }

    // Menor que, menor o igual que y left shift
    if (c == '<') {
        c = fgetc(arch);
        if (c == '<') return LEFT_SHIFT;
        if (c == '=') return MENOR_O_IGUAL_QUE;
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
        if (c == '=') return INCREMENTO_DIRECTO;
        if (c == '+') return INCREMENTO_EN_UNIDAD;
        ungetc(c, arch);
        return '+';
    }

    if (c == '-') {
        c = fgetc(arch);
        if (c == '=') return DECREMENTO_DIRECTO;
        if (c == '-') return DECREMENTO_EN_UNIDAD;
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

    if (c == ';') return FIN_DE_INSTRUCCION;
    if (c == ',') return SEPARACION_VARIABLES;
    if (c == ':') return INICIO;
    if (c == '"') return INICIO_FIN_CADENA;
    if (c == '\'') return INICIO_FIN_CARACTER;
    if (c == '(') return PARENTESIS_IZQUIERDA;
    if (c == ')') return PARENTESIS_DERECHA;
    if (c == '[') return CORCHETE_IZQUIERDA;
    if (c == ']') return CORCHETE_DERECHA;
    if (c == '=') return ASIGNACION;

    if (c == '%') {
        c = fgetc(arch);
        if (c == '%') return INICIO_FIN_COMENTARIO_EN_BLOQUE;
        ungetc(c, arch);
        return COMENTARIO_EN_LINEA;
    }
    return c;
}