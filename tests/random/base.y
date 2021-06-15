%{
void yyerror(char *s);
int yylex();
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char lexema[100];
%}

%token NUM ID SI

%%

command: expr;
expr: expr '+' term;
expr: expr '-' term;
expr: term;
term: term '*' fact;
term: fact;
fact: NUM;
fact:'(' expr ')';

%%
int main(){
        if(!yyparse()){
	         printf("cadena válida");
	}
	else{
	         printf("cadena inválida");
	}
        return 0;
}
/*análisis léxico*/
int yylex(){
        char c;
        int i;
        while((c=getchar())==' ');
        if(isdigit(c)){
                ungetc(c,stdin);
                scanf("%d",&yylval);
                return NUM;
        }
        else{
                i=0;
                if (isalpha(c)) {
                        do{
                                lexema[i++]=c;
                                c=getchar();
                        }while(isalnum(c));
                        ungetc(c,stdin);
                        lexema[i++]='\0';
                        if (strcmp(lexema,"if")==0)
                                return SI;
                        return ID;
                }
        }
        if(c=='\n'){
                return 0;
        }
        return c;
}
void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}
