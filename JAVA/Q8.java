//Write a program to find the missing number
import java.util.Scanner;
public class Q8 {
    public static void main(String[]args)
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter size of array");
        int n =scr.nextInt();
        int arr[]= new int [n];
        int sum=0;
        System.out.println("Enter Elements in array");
        for(int j=0;j<n;j++)
            {
                arr[j]=scr.nextInt();
                sum+=arr[j];
            }
        int len =arr.length;
        int ap = len*(len+1)/2;
        System.out.println("Missing number is : "+ (ap-sum));
        
        scr.close();
    }
}
