import java.util.Scanner;
public class Merge_Sort{
    public static void Merge(int[] arr, int start, int mid, int end){
        int sizeL = mid-start+1;
        int sizeR = end-mid;

        int[] Left = new int[sizeL];
        int[] Right = new int[sizeR];

        for (int i = 0; i < sizeL; i++) Left[i] = arr[start+i];
        for (int i = 0; i < sizeR; i++) Right[i] = arr[mid+1+i];

        int i = 0, j = 0, k = start;
        while (i < sizeL && j < sizeR){
            if (Left[i] <= Right[j]) arr[k++] = Left[i++];
            else arr[k++] = Right[j++];
        }

        while (i < sizeL) arr[k++] = Left[i++];
        while (j < sizeR) arr[k++] = Right[j++];

        Left = null; 
        Right = null; 
    }

    public static void MergeSort(int[] arr, int start, int end){
        if (start < end){
            int mid = start + (end-start)/2;

            MergeSort(arr, start, mid);
            MergeSort(arr, mid+1, end);

            Merge(arr, start, mid, end);
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
        
        MergeSort(arr, 0, size-1);
        System.out.println("\n\nAfter Sort:");
        for (int i = 0; i < size; i++)System.out.print(arr[i] + " ");
    }
}