import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class Main {

    public static int longestBalancedSubarrayLength(int k,List<Integer> arr) {
        int maxLen = 0;
        Map<Integer, Integer> counts = new HashMap<>();
        int left = 0;
        for (int right = 0; right < arr.size(); right++) {
            int num = arr.get(right);
            counts.put(num, counts.getOrDefault(num, 0) + 1);
            while (!isBalanced(counts, k)) {
                int leftNum = arr.get(left);
                counts.put(leftNum, counts.get(leftNum) - 1);
                if (counts.get(leftNum) == 0)
                    counts.remove(leftNum);
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    private static boolean isBalanced(Map<Integer, Integer> counts, int k) {
        int maxCount = 0;
        for (int count : counts.values()) {
            maxCount = Math.max(maxCount, count);
        }
        return maxCount <= k;
    }

    public static void main(String[] args) {
        int[] arr = {4,4,6,2,1,6,4,2};
        ArrayList <Integer>arr1 = new ArrayList<>();;
        for(int i=0;i<arr.length;i++)
        {
            arr1.add(arr[i]);
        }
        int k = 2;
        System.out.println(longestBalancedSubarrayLength(k,arr1)); // Output: 4
    }
}
