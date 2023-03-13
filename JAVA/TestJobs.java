class Solution {
    public int MaxNum(int []arr, int start, int end)
    {
        if(arr[start]>=arr[end])
        {
            return (start);
        }
        else
            return(end);
    }
    public int MinNum(int []arr, int start, int end)
    {
        if(arr[start]<arr[end])
        {
            return (start);
        }
        else
            return(end);
    }
    public boolean PredictTheWinner(int[] nums) {
        int len = nums.length,start=0;
        int end=len-1;
        int sum1=0; int sum2=0;
        int temp=0;
        do
        {
            int a;
            if(temp%2==0){
            a=MaxNum(nums,start,end);
            sum1+=nums[a];
            if(a==start)
                start++;
            else
                end--;
            }
            else{
                a =MinNum(nums,start,end);
                sum2+=nums[a];
                if(a==start)
                    start++;
                else
                    end--;
                }
                temp++;

        }
        while(start!=end);
        if(temp%2==0){
            sum1+=nums[start];
        }
        else
        {
            sum2+=nums[start];
        }
        System.out.println("PLAYER 1 ="+sum1+"  PLAYER 2 ="+sum2);
        if(sum1>=sum2)
            return true;
        else
            return false;

    }
}

public class TestJobs
{
    public static void main(String [] args)
    {
        int []arr ={1,5,233,7};
        Solution s1 = new Solution();
        boolean x = s1.PredictTheWinner(arr);
        System.out.println(x);
    }
}