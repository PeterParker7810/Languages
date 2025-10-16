import java.util.Scanner;
public class Radix_Sort{
    public static void CountingSort(int[] arr, int size, int last){
        int[] output = new int[size];
        int[] count = new int[10];
        
        for (int i = 0; i < size; i++) count[(arr[i]/last)%10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i-1];
        for (int i = size - 1; i >= 0; i--) output[--count[(arr[i]/last)%10]] = arr[i];
        
        for (int i = 0; i < size; i++) arr[i] = output[i];
    }

    public static void RadixSort(int[] arr, int size){
        int max = arr[0];
        for (int i = 1; i < size; i++) if (arr[i] > max) max = arr[i];
        for (int last = 1; max / last > 0; last *= 10) CountingSort(arr, size, last);
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
        
        RadixSort(arr,size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}