/*Write a program to calculate the length of Last Word 
Input: s = " fly me to the moon "
Output: 4
Explanation: The last word is "moon" with length 4.*/
import java.util.*;
public class Q2 {
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        String str;
        System.out.println("Enter a String :");
        str=scr.nextLine();
        int len=str.length();
        int L=len;
        int ans=0;
        for(int i=0;i<len; i++)
        {
            if(str.charAt(i)!=32)
                L=i;
        }
        while(str.charAt(L)!=' ')
        {
            ans++;
            L--;
        }
        System.out.println("The length of last string is :"+ans);
        scr.close();
    }
}
