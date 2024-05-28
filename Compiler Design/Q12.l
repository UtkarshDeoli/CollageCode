%{
#include <stdio.h>
#include "Q12.tab.h"
%}

%%
[a-zA-Z]+ { return id; }
[0-9]+ { return num; }
[-+/*=] { return yytext[0]; }
[ \t] ;
[\n] { return 0; }
. { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}
