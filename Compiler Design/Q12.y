%{
#include <stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%

input: /* empty */
     | input line
     ;

line: expr '\n'     { printf("Result: %d\n", $1); }
    ;

expr: expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr   { $$ = $1 / $3; }
    | '(' expr ')'    { $$ = $2; }
    | NUM             { $$ = $1; }
    ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *msg) {
    printf("Error: %s\n", msg);
    return 0;
}
