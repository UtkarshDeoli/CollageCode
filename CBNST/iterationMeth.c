#include<stdio.h>
#include<math.h>

#define   f(x)   cos(x)-3*x+1

#define   g(x)   (1+cos(x))/3

int main()
{
	 int temp=1;
	 float x0, x1, e;
	 printf("Enter initial guess: ");
	 scanf("%f", &x0);
	 printf("Enter tolerable error: ");
	 scanf("%f", &e);

	 printf("\nNo.\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  x1 = g(x0);
		  printf("%d\t%f\t%f\t%f\t%f\n",temp, x0, f(x0), x1, f(x1));
		
		  temp = temp + 1;
		  
		  x0 = x1;
		  
	 }while( fabs(f(x1)) > e);
	 
	 printf("\nRoot is %f , found after iterations :%d", x1 , temp);
}