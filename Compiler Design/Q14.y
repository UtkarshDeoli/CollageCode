%{
#include<stdio.h>
#include "lex.yy.c" 
void yyerror(char *s);
%}
%token num id
%left '+' '-'
%left '*' '/'
%%
S: E {printf("\n");}
;
E: E '+' E {printf("+");}
| E '*' E {printf("*");} 
|E '-' E {printf("-");}
| E '/' E {printf("/");}
| '(' E ')'
| num {printf("%d", yylval);}
| id {printf("%c", yylval);}
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
