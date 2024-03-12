
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


#define    f(x)    3*x - cos(x) -1
#define   g(x)   3 + sin(x)

void main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1;

	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);

	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }

		
		  x1 = x0 - f0/g0;

		
		  printf("Step: %d  x0: %f  f0: %f  x1:%f   f1: %f\n",step,x0,f0,x1,f1);
		  x0 = x1;
		  
		  step = step+1;
		  
		  f1 = f(x1);
		  
	 }while(fabs(f(x1))>e);
	
	 printf("\nRoot is: %f", x1);
	 getch();
}