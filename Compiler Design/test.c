void func(char** param){
 ++param;
}

int main(){

 char* string = (char*)malloc(64);
 strcpy(string, "hello_World");
 func(&string);
 func(&string);
 printf("%s\n", string);
 return 0;
} 
