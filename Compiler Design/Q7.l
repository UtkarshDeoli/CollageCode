
%{ 
%}


%% 
\/\/(.*) ; 
\/\*(.*[ \t\n]*)*\*\/ ; 
%% 

int yywrap(){return 1;}
int main(int k,char **argcv) 
{ 
yyin=fopen(argcv[1],"r"); 
yyout=fopen("out.c","w"); 
/*call the yylex function.*/ 
yylex(); 
return 0; 
} 
