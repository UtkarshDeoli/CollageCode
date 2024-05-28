%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%token A
%token B
%token NEWLINE

%%
start: AB | BA | AB NEWLINE | BA NEWLINE | start AB | start BA | start AB NEWLINE | start BA NEWLINE;
AB: A B | B A;
BA: B A | A B;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
   int result = yyparse();
    if (result == 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
