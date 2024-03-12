%{ 
#include<stdio.h>
#include<string.h>
int c=0;
%} 

%%
[a-zA-Z_][a-zA-Z0-9_]* {c++;printf("\tvalid identifier=%s",yytext);}
. ;
%%

int yywrap(){
    return 1;
}

int main(void)
{
    yylex();
    return 0;
}