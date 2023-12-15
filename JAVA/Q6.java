//Write a program to sort the people according to their height.
import java.util.*;
public class Q6 {
    static void Sort(int[] arr , String []str) {  
        int n = arr.length;  
        int temp = 0;  String tmp="";
         for(int i=0; i < n; i++)
         {  
            for(int j=1; j < (n-i); j++)
            {  
                if(arr[j-1] > arr[j])
                {                     
                    temp = arr[j-1];  
                    tmp = str[j-1];
                    arr[j-1] = arr[j];  
                    str[j-1]=str[j];
                    arr[j] = temp;
                    str[j]=tmp;
                }  
                          
            }  
         }  
  
    }  
    public static void main(String args[])
    {
        int n=0;
        Scanner scr = new Scanner(System.in);

        System.out.println("Enter the number of People :");
        n=scr.nextInt();

        int height[]= new int[n];
        String name[]= new String[n];

        for(int i =0; i <n ; i++)
        {
            System.out.println("Enter Name of :"+i);
            name[i]=scr.next();
            System.out.println("Enter Height of "+i);
            height[i]=scr.nextInt();
        }
        Sort(height, name);
        for(int i =0; i <n ; i++)
        {
            System.out.println(name[i]);
        }
        scr.close();
    }
}
