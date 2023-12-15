import java.util.*;
public class CountShort {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Size of array :");
        int n = s.nextInt();
        System.out.println("Enter Elements in array :");
        int arr[] = new int[n];
        int min=999,max=-999;
        for(int i =0; i<arr.length; i++)
        {
            arr[i]=s.nextInt();
            if(arr[i]<min)
                min=arr[i];
            if(arr[i]>max)
                max=arr[i];
        }
        s.close();
    }
}
