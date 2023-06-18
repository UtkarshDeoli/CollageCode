/*Given a sorted array of positive integers, design an algorithm and implement it using a program to
find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/

#include <iostream>
using namespace std;

void findIndices(int arr[], int size) {
    int i = 0, j = 1, k = 2;
    while (k < size) {
        int sum = arr[i] + arr[j];
        if (sum == arr[k]) {
            cout << "Indices found: " << i << ", " << j << ", " << k << endl;
            return;
        }
        else if (sum < arr[k])
            j++;
        else
            i++;
        
        if (i == j)  // Ensure i and j are distinct
            j++;
        if (j == k)  // Ensure j and k are distinct
            k++;
    }
    cout << "No such indices exist." << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    findIndices(arr, size);

    return 0;
}
