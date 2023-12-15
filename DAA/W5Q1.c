#include <stdio.h>
void maxocc(char arr[], int n)
{
    int fr[26] = {0};
    for (int i = 0; i < n; i++)
    {
        fr[arr[i] - 'a']++;
    }
    int max = -1;
    char result;
    for (int i = 0; i < n; i++)
    {
        if (max < fr[arr[i] - 'a'])
        {
            max = fr[arr[i] - 'a'];
            result = arr[i];
        }
    }
    if (max == 1)
    {
        printf("NO Duplicate Present\n");
    }
    else
    {
        printf("Maximum occuring character is %c and its frequency is %d\n", result, max);
    }
}
int main()
{
    char arr[] = {'c', 'd', 'e', 'f', 'q', 'c', 's', 'a'};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxocc(arr, size);
}