import java.util.Scanner;

public class Subsequences{
    public static void SubSequence(int index, int[] arr, int[] ds){
        if(index == arr.length){
            for (int i = 0; i < ds.length; i++) {
               if (ds[i] != 0) System.out.print(ds[i] + " ");
            }
            System.out.println();
            return;
        }

        //take or pick the element
        ds[index] = arr[index];
        SubSequence(index + 1, arr, ds);

        //not take or not pick the element
        ds[index] = 0;
        SubSequence(index + 1, arr, ds);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        int[] ds = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.print("\nOriginal Array: ");
        for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");

        System.out.println("\n\nAll Subsequences are: ");
        System.out.println("{}");
        SubSequence(0, arr, ds);
        
    }
}