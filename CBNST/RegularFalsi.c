#include<stdio.h>
#include<math.h>

int main(){

	int flag = 0;
	float x1,x2,x;
	
	float fx(float a)
	{
		float eq = a*a*a - 2*a -5;
		return eq;
	}
		
	do{
		printf("Enter the Value of x1 and x2: ");
		scanf("%f %f", &x1, &x2);
		if( fx(x1) * fx(x2) < 0)
		{
			flag = 1;
			printf("The root lies between the Interval\n");
		}
		else{
			printf("The root doesn't lies between the Interval");
		}
	}while(flag != 1);
	
	float error;
	printf("Enter the value of allowed Error: ");
	scanf("%f", &error);
	
	int iter = 1;
	do{
		x =x1 - (((x2 -  x1)/(fx(x2) - fx(x1)))*fx(x1));
		printf("%d Iteration, value of x: %f, value of fx(%f) is %f\n", iter, x, x, fx(x));
		if(fx(x1) * fx(x) < 0 )
			x2 = x;
		
		else if(fx(x) * fx(x2) < 0)
			x1 = x;
		iter++;
  	}while(fabs(fx(x))> error);
  	
  	
  }