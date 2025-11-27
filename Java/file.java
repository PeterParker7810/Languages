import java.util.Scanner;
public class file{
    public static int max(int a, int b) {return (a > b) ? a : b;}
    
    public static int Knapsack(int profits[], int weights[], int size, int cap) {
        int dp[][] = new int[size + 1][cap + 1];
        for (int i = 0; i <= size; i++) for (int j = 0; j <= cap; j++)
        if (i == 0 || j == 0) dp[i][j] = 0;

        for (int i = 1; i <= size; i++) {
            for (int w = 1; w <= cap; w++) {
                if (weights[i-1] <= w) {
                    dp[i][w] = max(dp[i-1][w], profits[i-1] + dp[i-1][w - weights[i-1]]);
                } else dp[i][w] = dp[i-1][w];
            }
        } return dp[size][cap];
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int size, capacity;
        System.out.print("Enter the no of Elements: ");
        size = input.nextInt();

        System.out.print("Enter the capacity of Knapsack: ");
        capacity = input.nextInt();

        int[] profits = new int[size];
        int[] weights = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.print("\nFor Element-" + (i + 1) + "\nEnter Profit: ");
            profits[i] = input.nextInt();
            System.out.print("Enter Weight: ");
            weights[i] = input.nextInt();
        }

        int maxProfit = Knapsack(profits, weights, size, capacity);
        System.out.println("\nMaximum Profit is: " + maxProfit);
    }
}