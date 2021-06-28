int LocalizarSimbolo(char* lexema, int toke);
int GenerarCodigo(int op, int a1, int a2, int a3);
void ImprimirTablaCodigo();
void InterpretarCodigo();
int GenerarTemporal();
int cantidad_simbolos = 0;
int cx = -1;
int cantidad_variables_temporales = 1;

typedef struct{
	int op;
	int a1;
	int a2;
	int a3;
} Codigo;

typedef struct{
	char nombre[MAX_SIZE];
	int token;
	double valor;
} Simbolo;

Codigo tabla_codigos[MAX_SIZE];
Simbolo tabla_simbolos[MAX_SIZE];

// Se hizo la corrección de errores, ahora compila y corre
// Comando: yacc grupo5_ER.y && gcc y.tab.c -lm -lfl && ./a.out

void ImprimirTablaCodigo(void) {
	printf("Tabla Codigo:\n");
	for (int pos = 0; pos <= cx; pos++) {
		printf("%d\t%d\t%d\t%d\n",
		tabla_codigos[pos].op,
		tabla_codigos[pos].a1,
		tabla_codigos[pos].a2,
		tabla_codigos[pos].a3);
	}
}

void interpretaCodigo(){
	int op, a1, a2, a3;
	printf("Tabla Codigo\n");
	for (int i = 0; i <= cx; i++) {
    	a1 = TCodigo[i].a1;
        a2 = TCodigo[i].a2;
        a3 = TCodigo[i].a3;
        op = TCodigo[i].op;
        if (op == SUMAR) {
        	tablaSimbolos[a1].valor=tablaSimbolos[a2].valor+tablaSimbolos[a3].valor;
		}
		if (op == ASIGNAR) {
			tablaSimbolos[a1].valor = tablaSimbolos[a2].valor ;
		}
		if (op == COMPIGUAL) {
			tablaSimbolos[a1].valor=(tablaSimbolos[a2].valor==tablaSimbolos[a3].valor);
		}
		if (op == SALTARF) {
			if(!tablaSimbolos[a1].valor)
				i=a2-1;
		}
		if (op == SALTAR) {
			i=a1-1;
		}
		if (op == COMPMENOR) {
			tablaSimbolos[a1].valor=(tablaSimbolos[a2].valor<tablaSimbolos[a3].valor);
		}
		if (op == IMPRIMIR) {
			printf("%lf\n",tablaSimbolos[a1].valor);
		}
    }
}

int GenerarTemporal(void) {
	int pos;
	char t[10];
	sprintf(t,"_T%d",nVarTemp++);
        pos=localizaSimbolo(t,ID);
        return pos;
}

int generaCodigo(int op,int a1,int a2,int a3){
        cx++;
        TCodigo[cx].op=op;
        TCodigo[cx].a1=a1;
        TCodigo[cx].a2=a2;
        TCodigo[cx].a3=a3;



}
void imprimeTablaSimbolos(){
        int i;
        printf("Tabla Simbolos\n");
        for(i=0;i<nSim;i++ ){
                printf("%d\t%s\t%d\t%lf\n",i, tablaSimbolos[i].nombre,tablaSimbolos[i].token,tablaSimbolos[i].valor);
        }

}
int localizaSimbolo(char *lexema,int token){
        int i;
        for(i=0;i<nSim;i++ ){
                if(!strcmp(tablaSimbolos[i].nombre,lexema)){
                        return i;
                }
        }

        strcpy(tablaSimbolos[nSim].nombre,lexema);
        tablaSimbolos[nSim].token=token;
        if(token == NUMBER){
                        tablaSimbolos[nSim].valor=atof(lexema);
        }
        else{
                tablaSimbolos[nSim].valor=0.0;
        }
        nSim++;
        return nSim-1;
}