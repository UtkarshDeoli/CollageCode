import java.util.*;
/*
Q1. Write a Java program to find the longest common prefix string amongst an
array of strings.If there is no common prefix, return an empty string "". 

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

public class Q1 {
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter the number of Strings in String array :");
        int num=scr.nextInt();
        String arr[] = new String[num];
        System.out.println("Enter Strings "+num+" in String array :");
        int min=100;
        for(int i =0;i<num;i++)
        {
            arr[i]=scr.next();
            if(arr[i].length()<min)
                min=arr[i].length();
        }
        String str="";
        char ch1=' ';
        for(int i =0; i<min ; i++)
        {
            for(int j =0; j<num-1 ; j++)
            {
                if(arr[j].charAt(i)==arr[j+1].charAt(i))
                    ch1=arr[j].charAt(i);
                else
                    {
                        ch1=' ';
                        break;
                    }
            }
            if(ch1!=' ')
                str+=ch1;
        }
        System.out.println("The Common Prefix in given String array is :"+str);

        scr.close();
    }

}
