import java.util.Scanner;
public class Fractional_Knapsack{
    public static float KnapSack(float[] profits, float[] weights, float[] pw, int capacity) {
        float result = 0;

        while (capacity > 0) {
            int index = -1;
            for (int i = 0; i < pw.length; i++) if (pw[i] != -1 && (index == -1 || pw[i] > pw[index])) index = i;

            if (index == -1) break;
            if (weights[index] <= capacity) {
                result += profits[index];
                capacity -= weights[index];
                pw[index] = -1;
            } else {
                result += pw[index] * capacity;
                capacity = 0;
            }
        }
        return result;
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int size, capacity;
        System.out.print("Enter the no of Elements: ");
        size = input.nextInt();

        System.out.print("Enter the capacity of Knapsack: ");
        capacity = input.nextInt();

        float[] profits = new float[size];
        float[] weights = new float[size];
        float[] pw = new float[size];
        for (int i = 0; i < size; i++) {
            System.out.print("\nFor Element-" + (i + 1) + "\nEnter Profit: ");
            profits[i] = input.nextFloat();
            System.out.print("Enter Weight: ");
            weights[i] = input.nextFloat();
            pw[i] = profits[i] / weights[i];
        }

        float maxProfit = KnapSack(profits, weights, pw, capacity);
        System.out.println("\nMaximum Profit is: " + maxProfit);
    }
}