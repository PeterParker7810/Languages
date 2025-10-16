import java.util.Scanner;
public class Selection_Sort{
    public static void SelectionSort(int[] arr, int size){
        for (int i = 0; i < size-1; i++){
            int min = i;
            for (int j = i+1; j < size; j++) if (arr[j] < arr[min]) min = j;
            if (min != i){
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
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
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
        
        SelectionSort(arr, size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}