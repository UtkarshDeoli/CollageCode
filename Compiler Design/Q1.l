%{
#include <stdio.h>
int lineCount = 0;
int spaceCount = 0;
int tabCount = 0;
int otherCount = 0;
%}

%%
[\n]    { lineCount++; }
[  \t]  { spaceCount++; }
[^\t]   { tabCount++; }
[^\t\n ]+ { otherCount++; }
%%

int yywrap(){ return 1; }

int main() {
    yylex();
    printf("Number of lines: %d\n", lineCount);
    printf("Number of spaces: %d\n", spaceCount);
    printf("Number of tabs: %d\n", tabCount);
    printf("Number of other characters: %d\n", otherCount);
    return 0;
}
