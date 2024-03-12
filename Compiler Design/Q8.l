%{
#include<stdio.h>
%}

%%
"<"[^>]*\> fprintf(yyout,"%s\n",yytext);
.|\n; 
%%

int yywrap()
{
return 1;
}

int main()
{
    char input[20]={};
    printf("Enter Name of the HTML File: ");
    scanf("%s", &input);
    yyin=fopen(input,"r");
    char out[20]={};
    printf("Enter Name of the Output File: ");
    scanf("%s", &out);
    yyout=fopen(out,"w");
    yylex();
    return 0;
}
