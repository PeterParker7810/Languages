
import java.util.Scanner;

public class Optimized_Bubble_Sort{

    public static void BubbleSort(int[] arr){
        for (int i = 0; i < arr.length-1; i++){
            boolean swapped = false;
            for(int j = 0; j < arr.length-i-1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        for(int i = 0; i < size; i++){
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.println("\nBefore Sorting:");
        for(int i = 0; i < size; i++){
            System.out.print(arr[i] + " ");
        }

        BubbleSort(arr);
        System.out.println("\n\nAfter Sorting:");
        for (int i = 0; i < size; i++){
            System.out.print(arr[i] + " ");
        }

        input.close();
    }
}