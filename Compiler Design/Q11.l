%{
#include <stdio.h>
%}
%x A B C DEAD
%%

[0-9]+\.[0-9]+ { BEGIN B; yymore(); }  // Float numbers
[0-9]+         { BEGIN A; yymore(); }  // Integer numbers
[A-Za-z_][A-Za-z0-9_]* { BEGIN C; yymore(); }  // Identifiers
[^\n]          { BEGIN DEAD; yymore(); }  // Invalid character
\n             { printf("Not Accepted\n"); BEGIN INITIAL; }

<A>[^\n]    { BEGIN DEAD; yymore(); }
<A>\n       { printf("Integer\n"); BEGIN INITIAL; }

<B>[^\n]    { BEGIN DEAD; yymore(); }
<B>\n       { printf("Float\n"); BEGIN INITIAL; }

<C>[^\n]    { BEGIN DEAD; yymore(); }
<C>\n       { printf("Identifier\n"); BEGIN INITIAL; }

<DEAD>[^\n] { yymore(); }
<DEAD>\n    { printf("Invalid\n"); BEGIN INITIAL; }

%%

// Auxiliary Functions
int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter String:\n");
    yylex();
    return 0;
}
