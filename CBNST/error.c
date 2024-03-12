#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float error(float trueVal, float approxVal)
{
    float absoluteError = fabs(trueVal - approxVal);

    float relativeError = absoluteError/trueVal;

    float percentageError = relativeError * 100;

    printf("Absolute Error: %f\nRelative Error: %f\nPercentage Error: %f", absoluteError,relativeError,percentageError);
}

int main(){
    float trueValue, approximateVal;
    printf("Enter True Value and Approximate value : ");
    scanf("%f %f", &trueValue, &approximateVal);

    error(trueValue, approximateVal);

}