/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/

#include<stdio.h>

int BinSearch(int arr[], int key ,int s, int e)
{
    if(s<e)
    {
        int mid =(s+e)/2;
        if(arr[mid]>key)
            {BinSearch(arr,key,s,mid-1);}
        else if(arr[mid]<key)
            {BinSearch(arr,key,mid+1,e);}
        else if(arr[mid]==key)
            return(mid);
    }
    else
        return(-1);
}

int main()
{
    int arr[]={6,6,34,34,34,50,69,69,77,77,77,84,91,91,91};
    printf("Elements of array are:\n");
    for (int i =0; i<15; i++)
        printf("%d\n",arr[i]);
    int key;
    printf("Enter the Number you want to search in array : ");
    scanf("%d", &key);
    int x =BinSearch(arr, key , 0 , 14);


    int temp =x;
    int count=0;


    if(x !=  -1)
        {printf("Found at index : %d\n",x);count++;}
    while(arr[--x]==key)
    {
        count++;
    }
    while(arr[++temp]==key)
    {
        count++;
    }
    printf("There are %d key in the array",count);

    
}