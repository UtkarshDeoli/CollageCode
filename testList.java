import java.util.*;

public class testList {

    public void reverse(LinkedList<Integer> list)
    {
        
    }


    public static void main(String[]args)
    {
        LinkedList<Integer> temp = new LinkedList<Integer>();
        temp.add(10);
        temp.add(9);
        temp.add(8);
        temp.add(7);
        temp.add(6);
        temp.add(5);
        temp.add(4);
        System.out.println(temp.size());
        for(int i =0 ; i<temp.size(); i++)
        {
            System.out.print(temp.get(i)+" -> ");
        }
        System.out.print("END \n");
    }
}
