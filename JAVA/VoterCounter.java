import java.util.Scanner;
public class VoterCounter {

    public static void main(String[]args)
    {
        Scanner scr = new Scanner(System.in);
        int voter;int toContinue;
        int max=0, maxIndex=0;
        int vote[]={0,0,0,0,0};
        String party[]={"Nota","BJP","AAP","RRA","LPP"};
        do{
        System.out.println("Enter[0] For NOTA");
        System.out.println("Enter[1] For BJP");
        System.out.println("Enter[2] For AAP");
        System.out.println("Enter[3] For RRA");
        System.out.println("Enter[4] For LPP");
        voter=scr.nextInt();
        vote[voter]++;
        System.out.println("Enter 0 to EXIT");  
        toContinue=scr.nextInt();
        }
        while(toContinue!=0);
        for(int i =0; i<5;i++)
           { 
                System.out.print(party[i]+ "  ");
                System.out.println(vote[i]); 
            
            if(max<vote[i])
               { maxIndex=i;
                max =vote[i];
                }}
        System.out.println("The Winner is "+party[maxIndex]+" they won with "+max+"Votes");



    }
    
}
