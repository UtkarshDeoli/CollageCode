//Write a program to check if any value appears at least twice in an array.
import java.util.*;
public class Q5 {

    static boolean twice(int arr[])
    {
        for(int i=0; i<arr.length-1; i++)
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr[i]==arr[j])
                    return true;
            }
        }
        return false;
    }
    public static void main(String []args)
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
        System.out.println(twice(arr));
        scr.close();
    }
}
