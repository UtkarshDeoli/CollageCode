import java.util.*;
public class MaxAlphabet {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        String str = s.nextLine();
        str=str.toUpperCase();
        int len= str.length();
        int arr[] = new int [26];
        for(int i =0; i<len ; i++)
        {
            if(str.charAt(i)!=' ')
            {
                int x = (str.charAt(i))-65;
                arr[x]++;
            }
        }
        int max=0 , maxIndex=0;
        for(int i=0; i<26; i++)
            if(arr[i]>max)
            {
                maxIndex=i;
                max = arr[i];
            }
        System.out.println("The Most Occuring alphabet was :"+ ((char)(maxIndex+65)));
        s.close();
    }
}
