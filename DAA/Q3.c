/*
Given an already shorted array of +ve integers design an algo to & implement using program to
find the key element from an array arr[n] search at the indices arr[0],arr[2],arr[4]....arr[2^k] and so on
once interval arr[2^k]<key<arr[2^k+1] is found perform lenier search from index k to k+1 to find the key. (Complexity < O(n)) 
*/
#include<stdio.h>
#include<math.h>
int LenierSearch(int arr[], int s , int e , int key)
{
    int count=0;
    for(int i=s;i<=e;i++)
        {   count++;
            if(arr[i]==key)
            return(count);}
    return(-1);
}
int main()
{

    int arr[]={6,13,28,34,44,50,69,77,84,91};
    printf("Enter Elements in array are :\n");
    for (int i =0; i<10; i++)
        printf("%d\n",arr[i]);
    int key;
    printf("Enter the Number you want to search in array : ");
    scanf("%d", &key);
    int count=0;int x=-1;
    for(int i =1; i<10; i=pow(2,i))
    {
        count++;
        if(arr[i]==key)
            printf("Key found after %d comparisions ",count);
        else if(key<arr[(int)pow(2,i+1)]&&key>arr[(int)pow(2,i)])
            x =LenierSearch(arr, (int)pow(2,i)+1,(int)pow(2,i+1)-1,key);
    }
    if(x!=-1)
        printf("Hey Key found after %d comparisions ",count+x);
}