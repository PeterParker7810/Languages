import java.util.Scanner;
public class Heap_Sort{
    public static void Heapify(int[] arr, int size, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && arr[left] > arr[largest]) largest = left;
        if (right < size && arr[right] > arr[largest]) largest = right;

        if (largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            Heapify(arr, size, largest);
        }
    }

    public static void HeapSort(int[] arr, int size){
        for (int i = size/2+1; i >= 0; i--) Heapify(arr, size, i);
        for (int i = size-1; i >= 0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            Heapify(arr, i, 0);
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
        
        HeapSort(arr,size);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}