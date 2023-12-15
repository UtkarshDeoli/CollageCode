public class Accounts {
    String name;
    String accNumber;
    String accType;
    double balance;
    Accounts(String name , String accNumber , String accType , double balance)
    {
        this.name= name;
        this.accNumber=accNumber;
        this.accType=accType;
        this.balance=balance;
    }
    void deposit(double x)
    {
        balance+=x;
        System.out.println("The amount of Rs:"+x+" Was Deposited Successfully");
    }
    void widraw(double x)
    {
        System.out.print("Widrawn amount :"+x);
        if(x<balance)
        {
            System.out.println(" Successfully");
            balance-=x;
        }
        else
            System.out.println(" Unsuccessful LOW BALANCE");
    }
    void display()
    {
        System.out.println("==========WELCOME TO SBI==========");
        System.out.print("Name :"+name+"\t\t\t");
        System.out.println("Account no: "+accNumber);
        System.out.print("Account Type :"+accType+"\t\t\t");
        System.out.println("Your BALANCE is : "+balance);
    }
}
