import java.util.Scanner;
public class Counting_Sort{
    public static void CountingSort(int[] arr, int size){
        int max = arr[0], min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        int[] count = new int[max-min+1];
        for (int i = 0; i < size; i++) count[arr[i]-min]++;
        int index = 0;

        for (int i = 0; i < (max-min+1); i++) for (int j = 0; j < count[i]; j++) arr[index++] = i+min;
        count = null;
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
        
        CountingSort(arr, size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}