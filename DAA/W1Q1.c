/*
Given an array of non negetive integers design an ango and implement it 
to find wether a key is presnt or not (lenier search)
Also find the number of comparision to find key
*/


#include<stdio.h>

int main()
{
    int n;
    printf("Enter the Number of Elements u want to input in array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Elements %d in array :\n",n);
    for (int i =0; i<n; i++)
        scanf("%d", &arr[i]);
    int key;
    printf("Enter the Number you want to search in array : ");
    scanf("%d", &key);
    for(int i=0;i<n;i++)
        if(arr[i]==key)
            printf("Key Found after %d Comparisions",i+1);
}