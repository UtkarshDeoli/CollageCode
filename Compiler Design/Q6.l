%{
	
%}


%%
[ \n\t]+ {fprintf(yyout, " ");}
.	 { fprintf(yyout, "%s", yytext); }
%%

int yywrap(void) 
{ 
	return 1; 
} 


int main()
{

	extern FILE *yyin, *yyout;
	yyin = fopen("Input.txt", "r");
	yyout = fopen("Output.txt", "w");
	yylex();
	return 0;
}
