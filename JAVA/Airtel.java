import java.util.*;

public class Airtel
{
    public static void main(String[] args)
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Name of the Coustmer :");
        String name = scr.nextLine();
        System.out.println("Number of the Coustmer :");
        String no = scr.next();
        System.out.println("Number of calls of the Coustmer :");
        int calls = scr.nextInt();
        TelCall b1 = new TelCall(no, name, calls);
        b1.compute();
        b1.display();
        scr.close();
    }
}