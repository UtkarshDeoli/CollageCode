%{
#include <stdio.h>
#include "lex.yy.c"
void yyerror(char *s);
%}
%token num
%left '+' '-'
%left '*' '/' '%'
%left '('')'
%%
S:E {printf("Result: %d\n", $1); return 0;} E:E'+'E{$$=$1+$3;} |E'-'E{$$=$1-$3;}

|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'%'E{$$=$1%$3;}
| '('E')' {$$=$2;}
| num { $$ = $1; }
;
%%
int main()
{
printf("Enter the arithmetic expression: ");

yyparse();
return 0;
}

void yyerror(char *s)
{
  printf("error: %s\n",s);
}
