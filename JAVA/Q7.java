//Write a program to count pairs of similar Strings

import java.util.Scanner;
public class Q7 {
    static boolean IsSimilar(String s1, String s2)
    {
        int arr1[]=new int[26];
        int arr2[]=new int[26];
        int i=0;int temp;
        while(i<s1.length()||i<s2.length())
        {
            if(i<s1.length())
            {
                temp = ((int)s1.charAt(i))-97;
                arr1[temp]++;
            }
            if(i<s2.length())
            {
                temp = ((int)s2.charAt(i))-97;
                arr2[temp]++;
            }
            i++;
        }
        for(i =0; i<26; i++)
        {
            if((arr1[i]>0&&arr2[i]==0)||(arr1[i]==0&&arr2[i]>0))
                return false;
        }
        return true;
    }
    public static void main(String[]args)
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter the Size of array:");
        int n = scr.nextInt();
        String str[] = new String[n];
        System.out.println("Enter "+n+" Strings in array:\n");
        for(int i=0; i<n ;i++)
        {
            str[i]=scr.next();
        }

        int pairs=0;

        for(int i=0; i<n ;i++)
        {
            for(int j=i+1; j<n ;j++)
            {
                if(IsSimilar(str[i], str[j]))
                    pairs++;
            }
        }
        System.out.println("There are :"+pairs+" pairs");

        scr.close();
    }
}
