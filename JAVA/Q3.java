/*Write a program to return corresponding column title as it appears in an Excel
sheet for a given number
 */

import java.util.*;
public class Q3 {
    public static void main(String args[])
    {
        Scanner scr = new Scanner (System.in);
        int x=0;
        System.out.println("Enter the Excel Column num: ");
        x=scr.nextInt();
        int temp=x;
        String str="";
        while(temp>26)
        {
            int a = x%26;
            char ch =(char)(a+64);
            str+=ch;
            temp=temp/26;
        }
        temp+=64;
        char ch= (char)temp;
        str=ch+str;
        System.out.println(str);
        scr.close();
    }
}
