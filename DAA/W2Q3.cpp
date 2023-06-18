 /*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.*/

#include <iostream>
#include <unordered_set>
using namespace std;

int countPairsWithDifferenceK(int arr[], int size, int K) {
    unordered_set<int> hashSet;
    int count = 0;

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int potentialPair1 = num + K;
        int potentialPair2 = num - K;

        if (hashSet.count(potentialPair1) > 0)
            count++;
        if (hashSet.count(potentialPair2) > 0)
            count++;

        hashSet.insert(num);
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    int pairCount = countPairsWithDifferenceK(arr, size, K);
    cout << "Number of pairs with difference " << K << ": " << pairCount << endl;

    return 0;
}
