/*.Given an unsorted array of integers, design an algorithm and implement a program to sort this array using
selection sort. Your program should also find number of comparisons and number of swaps required.*/
// selection sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n, i;
    clock_t start, end;
    printf("enter no. of elements:");
    scanf("%d", &n);
    int a[n];
    printf("enter elements:");
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
            if (min != i)
            {
                int temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
        }
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