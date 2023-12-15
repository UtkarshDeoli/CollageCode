/*Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion
sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times
the array elements are shifted from their place) required for sorting the array.*/

// insertion sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    clock_t start, end;
    int i, n;
    printf("enter no.of elements:");
    scanf("%d", &n);
    int a[n];
    printf("enter elements:");
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }
    start = clock();
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    end = clock();
    double time_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n%lf", time_taken);
}
