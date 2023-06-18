#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> arr;
    arr.push_back(10);
    arr.push_front(11);
    for(int i : arr)
    {
        cout<<i<<endl;
    }
    for(int i = 0; i <arr.size() ; i++)
    {
        cout<<arr[i]<<endl;
    }
}