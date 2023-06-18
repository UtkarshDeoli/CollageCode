#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
void merge(int arr[], int l,
           int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
}
while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
}
while (j < n2)
{
        arr[k] = R[j];
        j++;
        k++;
}
}
void mergeSort(int arr[],
               int l, int r)
{
if (l < r)
{
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
}
int main()
{
int arr[] = {12, 23, 45, 67, 89, 90, 87, 65, 43, 32};
int size = sizeof(arr) / sizeof(arr[0]);
int k = 35;
mergeSort(arr, 0, size - 1);
int x = -1;
for (int i = 0; i < size - 1; i++)
{
    x = binarySearch(arr, 0, size - 1, k - arr[i]);
    if (x != -1)
    {
        printf("%d %d", arr[i], arr[x]);
        break;
    }
}
if (x == -1)
{
    printf("No Such Element Found");
}
}
