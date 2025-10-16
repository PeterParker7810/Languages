import java.util.Scanner;
public class Quick_Sort_using_Tail_Recursion{
    public static int Partition(int[] arr, int start, int end){
        int pivot = arr[end];
        int i = start-1;

        for (int j = start; j < end; j++){
            if (arr[j] < pivot){
                int temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;
        return i+1;
    }

    public static void QuickSort(int[] arr, int start, int end){
        if (start < end) {
            int part = Partition(arr, start, end);
            
            if (part-start < end-part) {
                QuickSort(arr, start, part-1);
                QuickSort(arr, part+1, end);
            } else {
                QuickSort(arr, part+1, end);
                QuickSort(arr, start, part-1);
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
        
        QuickSort(arr, 0, size-1);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}