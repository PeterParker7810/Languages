import java.util.Scanner;
public class Insertion_Sort{
    public static void InsertionSort(int[] arr, int size){
        for (int i = 1; i < size; i++){
            int curr = arr[i];
            int prev = i-1;

            while (prev >=0 && arr[prev] > curr){
                arr[prev+1] = arr[prev];
                prev--;
            } arr[prev+1] = curr;
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
        
        InsertionSort(arr, size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}