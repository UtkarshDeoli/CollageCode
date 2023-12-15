import java.util.*;

class W4Q2 {
    static int comparisonCount, swapCount;

    static int partition(int[] arr, int low, int high) {
        int pivotIndex = low + new Random().nextInt(high - low + 1);
        int pivot = arr[pivotIndex];
        swap(arr, pivotIndex, high); // Move pivot to the end
        int i = low - 1;

        for (int j = low; j < high; j++) {
            comparisonCount++;
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
                swapCount++;
            }
        }
        swap(arr, i + 1, high); // Move pivot to its correct position
        swapCount++;
        return i + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
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

            comparisonCount = 0;
            swapCount = 0;

            quickSort(arr, 0, n - 1);

            // Output sorted array
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();

            // Output number of comparisons and swaps
            System.out.println("Comparisons: " + comparisonCount);
            System.out.println("Swaps: " + swapCount);

            t--;
        }
    }
}
