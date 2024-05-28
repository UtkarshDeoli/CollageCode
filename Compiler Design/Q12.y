%{
#include <stdio.h>
#include "lex.yy.c" 
void yyerror(char *s);
%}
%token num id
%left '+' '-'
%left '*' '/' '%'
%%
S:E {printf("Valid arithmetic expression\n"); return 0; }
|E'='E {printf("Valid arithmetic expression\n"); return 0; }
E:E'+'E
|E'-'E
|E'*'E
|E'/'E
|E'%'E
|'('E')'
|num
|id
;
%%
int main()
{
printf("Enter the expression: ");
yyparse();
return 0;
}

void yyerror(char *s)
{
  printf("error: %s\n",s);
}
