
    %{ 
    %}

    %% 
    \/\/(.*) ; 
    %% 

    int yywrap(void) 
    { 
        return 1; 
    } 
    int main(int k,char **argcv) 
    { 
        yyin=fopen(argcv[1],"r"); 
        yyout=fopen("test.c","w"); 
        yylex(); 
        return 0; 
    }
