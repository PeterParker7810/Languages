import java.util.Scanner;
public class Frog_Jump{
    public static void FrogJump(int[] arr, int[] solutions, int[] counter, int index, int energy) {
        if (index >= arr.length - 1) {
            solutions[counter[0]++] = energy;
            return;
        }

        // Jump 1 step
        FrogJump(arr, solutions, counter, index + 1, energy + Math.abs(arr[index] - arr[index + 1]));

        // Jump 2 steps
        if (index + 2 < arr.length) FrogJump(arr, solutions, counter, index + 2, energy + Math.abs(arr[index] - arr[index + 2]));
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        int[] solutions = new int[size*size];
        int[] counter = new int[1];
        counter[0] = 0;
        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.println("\nElements in the array are:");
        for (int val : arr) System.out.print(val + " ");

        FrogJump(arr, solutions, counter, 0, 0);
        int minEnergy = solutions[0];
        for (int i = 1; i < counter[0]; i++) if (solutions[i] < minEnergy) minEnergy = solutions[i];
        System.out.println("\n\nMinimum Energy Required: " + minEnergy);
    }
}