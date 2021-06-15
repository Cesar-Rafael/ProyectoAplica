/*
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
*/