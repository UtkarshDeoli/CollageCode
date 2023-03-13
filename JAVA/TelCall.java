
public class TelCall
{
    String phno;
    String sname;
    int n;
    double amt;
    TelCall(String x , String y ,int z)
    {
        phno =x;
        sname =y;
        n=z;
    }
    void compute()
    {
        if(n<=100)
            amt =500;
        else if(n>100&&n<=200)
            amt=500+(n-100);
        else if(n>200&&n<=300)
            amt=600+((n-200)*1.20);
        else
            amt=600+120+((n-300)*1.5);
    }
    void display()
    {
        System.out.println("===========AIRTEL BHARATI LIMITED===========");
        System.out.print("Name: "+sname+"\t\t\t");
        System.out.println("Phone No: "+phno);
        System.out.print("Number of calls: "+n+"\t\t\t");
        System.out.print("Bill Amount: "+amt);
    }
}