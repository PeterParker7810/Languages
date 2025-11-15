import java.util.Scanner;
public class Bubble_Sort{
    public static void BubbleSort(int[] arr, int size){
        for (int i = 0; i < size-1; i++){
            for (int j = 0; j < size-1-i; j++){
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
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
        for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");
        
        BubbleSort(arr, size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");
    }
}