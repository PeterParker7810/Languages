import java.util.Scanner;

public class Min_and_Max_using_Divide_and_Conquer {
    public static void findMinMax(int[] arr, int start, int end, int[] min, int[] max) {
        if (start == end) {
            if (arr[start] < min[0]) min[0] = arr[start];
            if (arr[start] > max[0]) max[0] = arr[start];
            return;
        }

        if (start + 1 == end) {
            if (arr[start] > arr[end]) {
                if (arr[end] < min[0]) min[0] = arr[end];
                if (arr[start] > max[0]) max[0] = arr[start];
            } else {
                if (arr[start] < min[0]) min[0] = arr[start];
                if (arr[end] > max[0]) max[0] = arr[end];
            }
            return;
        }

        int mid = (start + end) / 2;
        findMinMax(arr, start, mid, min, max);
        findMinMax(arr, mid + 1, end, min, max);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        int[] min = {arr[0]};
        int[] max = {arr[0]};

        findMinMax(arr, 0, size - 1, min, max);

        System.out.println("\nMin Element: " + min[0]);
        System.out.println("Max Element: " + max[0]);
    }
}