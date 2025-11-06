import java.util.Scanner;
public class Frog_Jump_using_dynamic_programming{
    public static int FrogJump(int[] arr, int[] dp, int index) {
        if (index == 0) return 0;
        if (index == 1) return Math.abs(arr[1] - arr[0]);
        if (dp[index] != -1) return dp[index];

        int left = FrogJump(arr, dp, index - 1) + Math.abs(arr[index] - arr[index - 1]);
        int right = FrogJump(arr, dp, index - 2) + Math.abs(arr[index] - arr[index - 2]);

        return dp[index] = Math.min(left, right);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        int[] dp = new int[size];
        for (int i = 0; i < size; i++) dp[i] = -1;
        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.println("\nElements in the array are:");
        for (int val : arr) System.out.print(val + " ");

        int result = FrogJump(arr, dp, size - 1);
        System.out.println("\n\nMinimum Energy Required: " + result);
    }
}