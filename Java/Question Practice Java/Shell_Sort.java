import java.util.Scanner;
public class Shell_Sort{
    public static void ShellSort(int[] arr, int size){
        int gap = size/2;
        while (gap > 0){
            for (int i = gap; i < size; i++){
                int curr = arr[i];
                int prev = i-gap;

                while (prev >= 0 && arr[prev] > curr){
                    arr[prev+gap] = arr[prev];
                    prev -= gap;
                } arr[prev+gap] = curr;
            } gap /= 2;
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();
        int[] arr = new int[size];

        for (int i = 0; i < size; i++){
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.println("\nBefore Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
        
        ShellSort(arr,size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}