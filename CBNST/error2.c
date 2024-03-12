#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float x,y,z;
	x = y = z =1;
	float dx, dy, dz;
	dx = dy = dz = 0.001;
	
	float u = (5*x*y*y)/(z*z*z);
	
	float maxRelativeError = (fabs((5*y*y)/(z*z*z)*dx) + fabs((10*x*y)/(z*z*z)*dy)+ fabs((-15*x*y*y)/(z*z*z) *dz))/u;
	
	float maxPercentageError = maxRelativeError*100;
	
	printf("Max Relative Error: %f\n", maxRelativeError);
	printf("Max Percentage Error: %f\n", maxPercentageError);
	
}