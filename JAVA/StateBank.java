import java.util.*;
public class StateBank {
    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);
        System.out.println("Name of the Coustmer :");
        String name = scr.nextLine();
        System.out.println("Account no of the Coustmer :");
        String no = scr.next();
        System.out.println("Account Type of the Coustmer :");
        String type = scr.next();
        System.out.println("Primary balance:");
        int bal = scr.nextInt();

        Accounts a1 = new Accounts(name, no, type, bal);
        
        a1.display();
        System.out.println();
        a1.deposit(10000.00);
        System.out.println();
        a1.widraw(999999);
        System.out.println();
        a1.widraw(500);
        System.out.println();
        a1.display();
        scr.close();
    }
}
