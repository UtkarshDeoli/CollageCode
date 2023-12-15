/*Given an unsorted array of positive integers, design an algorithm and implement it using a program to
find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log
n)).*/
// quick sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int partition(int arr[], int start, int end)
{
    int pivot = end;
    int i = start;
    int j = end - 1;
    while (i < j)
    {
        while (arr[i] < arr[pivot] && i < j)
        {
            i++;
        }
        while (arr[j] > arr[pivot] && i < j)
        {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if (arr[i] > arr[pivot])
    {
        int temp = arr[i];
        arr[i] = arr[pivot];
        arr[pivot] = temp;
        return i;
    }
    return pivot;
}
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}
int main()
{
    int i, j, n;
    clock_t start, end;
    start = clock();
    printf("Enter no.of elements:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }
    quicksort(arr, 0, n);
    printf("elements after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    end = clock();
    double time_taken = (((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n%lf", time_taken);
}