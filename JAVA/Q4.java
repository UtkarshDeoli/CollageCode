/*Write a program to check valid palindrome. */

import java.util.*;
public class Q4 {
    static boolean palindrome(String a)
    {
        for(int i=0; i<(a.length()/2); i++)
        {
            if(a.charAt(i)!=a.charAt(a.length()-i-1))
                return false;
            
        }
        return true;
    }
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Enter a String :");
        String str = scr.nextLine();
        str = str.toLowerCase();
        String a="";
        for(int i=0; i<str.length(); i++)
        {
            if(str.charAt(i)>=97 && str.charAt(i)<=122)
                a+=str.charAt(i);
        }
        System.out.println(palindrome(a));
        scr.close();
    }
}
