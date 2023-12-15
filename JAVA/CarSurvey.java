/* Write a Program to : */


import static java.lang.System.*;
import java.util.Scanner;
public class CarSurvey {
    public static void main(String []args)
    {
        int choice;
        int survey[][]=new int[4][4];
        Scanner scr = new Scanner(System.in);
        for(int i =0; i<4; i++)
        {
            for(int j=0;j<4;j++)
                survey[i][j]=0;
        }
        int carCode;
        int cityCode;
        do{
            out.println("**MAIN MENU**");
            out.println("Press[0] for Delhi");
            out.println("Press[1] for Mumbai");
            out.println("Press[2] for Kolkata");
            out.println("Press[3] for Chennai");
            out.println("Press[0] for K-10");
            out.println("Press[1] for Zen");
            out.println("Press[2] for Wagnor");
            out.println("Press[3] for SX-4");
            out.print("Enter City Code :");
            cityCode=scr.nextInt();
            out.print("Enter Car Code :");
            carCode=scr.nextInt();
            survey[cityCode][carCode]++;
            out.println("Press 1 to continue 0 to Exit :");
            choice=scr.nextInt();
        }
        while(choice==1);

        out.println("\t\tk-10\t\tzen\t\twagonar\t\tSX-4");
        for(int i =0;i<4;i++)
        {
            if(i==0)
                out.print("Delhi  ");
            else if(i==1)
                out.print("Mumbai ");
            else if(i==2)
                out.print("Kolkata");
            else if(i==3)
                out.print("Chennai");
            for(int j =0; j<4;j++)
            {
                out.print("\t\t"+survey[i][j]);
            }
            out.println();
        }
        scr.close();

    }
    
}
