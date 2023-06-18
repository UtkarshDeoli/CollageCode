import java.util.*;

class W4Q3 {
    static int kthSmallest(int[] arr, int left, int right, int k) {
        if (k > 0 && k <= right - left + 1) {
            int pivotIndex = partition(arr, left, right);

            if (pivotIndex - left == k - 1)
                return arr[pivotIndex];
            if (pivotIndex - left > k - 1)
                return kthSmallest(arr, left, pivotIndex - 1, k);
            return kthSmallest(arr, pivotIndex + 1, right, k - pivotIndex + left - 1);
        }

        return Integer.MAX_VALUE; // If k is out of range, return a large value
    }

    static int partition(int[] arr, int left, int right) {
        int pivot = arr[right];
        int i = left;

        for (int j = left; j <= right - 1; j++) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }
        swap(arr, i, right);
        return i;
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases
        sc.nextLine(); // Consume the newline character

        while (t > 0) {
            int n = sc.nextInt(); // Size of array
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int k = sc.nextInt(); // Kth smallest or largest element

            int result = kthSmallest(arr, 0, n - 1, k);

            if (result != Integer.MAX_VALUE)
                System.out.println(result);
            else
                System.out.println("not present");

            t--;
        }
    }
}
