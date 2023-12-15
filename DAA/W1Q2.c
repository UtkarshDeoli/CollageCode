/*
Given an already shorted array of +ve integers design an algo to & implement using program to 
find wether a given key element is present in the array or not , 
Also find the total number of comparisions required to find the elements
Complexity = O(log n)
*/

#include<stdio.h>
int count =0;
int BinSearch(int arr[], int key ,int s, int e)
{
    if(s<e)
    {
        int mid =(s+e)/2;
        if(mid>key)
            {BinSearch(arr,key,s,mid-1);count++;}
        else if(mid<key)
            {BinSearch(arr,key,mid+1,e);count++;}
        else if(mid==key)
            return(count);
    }
    else
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

    int x =BinSearch(arr, key , 0 , 9);
    if(x !=  -1)
        printf("Found after %d comparision",x);
}