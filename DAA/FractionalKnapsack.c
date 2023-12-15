/*
no->        1   2   3   4   5
Name->      A   B   C   D   E
weight ->   10  5   3   4   5
Price ->    20  5   9   2   12
You have a bag of capacity 15kg what items must be chosen for max profit
*/

#include<stdio.h>

int findMax(float arr[])
{
    int max =0; int index =0;
    for(int i=0; i<5;i++)
    {
        if(arr[i]>max)
            max=arr[i];
            index=i;
    }
    return (index);
}

int main()
{
    int weightarr[]={10,5,3,4,5};
    int pricearr[]={20,5,9,2,12};
    float ratio[5];
    for(int i =0;i<5;i++)
        ratio[i]=weightarr[i]/pricearr[i];
    int price=0; int weight=0; int index=0;
    while(weight<15)
    {
        index = findMax(ratio);
        ratio[index]=ratio[index]/100;
        weight+=weightarr[index];
        price+=pricearr[index];
    }
    if(weight>15)
    {
        weight-=weightarr[index];
        price-=pricearr[index];
        int temp = 15-weight;
        weight=weight+temp;
        price=price+(temp*(weightarr[index]/pricearr[index]));
    }
    printf("%d Profit ", price);
}