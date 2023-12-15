/*Given an unsorted array of integers, design an algorithm and implement it using a program to sort
an array of elements by dividing the array into two subarrays and combining these subarrays after
sorting each one of them. Your program should also find number of comparisons and inversions
during sorting the array. */

import java.util.*;

class W4Q1
{
    static int comparisons =0;
    static int shifts=0;
    static void InsertionSort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
                shifts++;
            }
            comparisons++;
            arr[j + 1] = key;
        }
        System.out.println("\nNumber of Comp. :"+comparisons+"\nNumber of shifts :"+shifts);
    }
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        
        int n=0;
        System.out.println("Enter the size of Array: ");
        n= scr.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter elements in Array: ");
        for(int i =0; i<n; i++)
        {
            arr[i]=scr.nextInt();
        }
        System.out.println("Unsorted Array: ");
        for(int i =0; i<n; i++)
        {
            System.out.print(" "+arr[i]);
        }
        InsertionSort(arr);
        System.out.println("\nSorted Array: ");
        for(int i =0; i<n; i++)
        {
            System.out.print(" "+arr[i]);
        }
        scr.close();
    }
}