%{
#include "y.tab.h"
%}

%%

[0-9]+          { yylval.num = atoi(yytext); return NUM; }
[-+\/*\n]       { return yytext[0]; }
[ \t]           ; /* ignore whitespace */
.               ;

%%

int yywrap(void) {
    return 1;
}
