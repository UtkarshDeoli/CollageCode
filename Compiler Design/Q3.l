/*lex code to accept a valid integer 
and float value using lex program.*/
	
%{ 
int valid_int=0, valid_float=0; 
%} 

%% 
[-+]?[0-9]+ valid_int++; 
[-+]?[0-9]+[.][0-9]+$ valid_float++; 
. {}; 
%% 

int yywrap(){
    return 1;
}

int main() 
{ 
yylex(); 
if(valid_int!=0) printf("Valid Integer number found : %d\n",valid_int); 
if(valid_float!=0) printf("Valid Float number : %d\n",valid_float); 
else printf("Not valid Integer/Float number\n"); 
return 0; 
} 
