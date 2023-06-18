/*Write a program to move all 0's to the end of it while maintaining the relative order of the non-zero
elements*/

import java.util.Scanner;
public class Q9 {
    public static void main(String[]args)
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter size of array");
        int n =scr.nextInt();
        int arr[]= new int [n];
        System.out.println("Enter Elements in array");
        for(int j=0;j<n;j++)
            {
                arr[j]=scr.nextInt();
            }
        for(int i=0; i<n ; i++)
        {
            if(arr[i]==0)
            {
                for(int j=i;j<n-1;j++)
                {
                    int temp=arr[j];
                    arr[j]= arr[j+1];
                    arr[j+1]=temp;
                }
                n--;
            }
        }
        System.out.print("Shifted array :\n");
        for(int j=0;j<arr.length;j++)
        {
            System.out.print(" "+arr[j]);
        }
        scr.close();
    }
}
