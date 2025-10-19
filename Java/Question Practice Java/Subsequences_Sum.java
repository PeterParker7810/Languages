import java.util.Scanner;

public class Subsequences_Sum{
    public static void SubSequence(int index, int[] arr, int[] ds, int check, int[] found){
        if(index == arr.length){
            int sum = 0;
            for (int i = 0; i < ds.length; i++) if (ds[i] != 0) sum += ds[i];
            if (sum == check) {
                System.out.print("The Numbers ");
                for (int i = 0; i < ds.length; i++) if (ds[i] != 0) System.out.print(ds[i] + " ");
                System.out.println("add upto " + check);
                found[0] = 1;
                return;
            } else return;
        }

        //take or pick the element
        ds[index] = arr[index];
        SubSequence(index + 1, arr, ds, check, found);

        //not take or not pick the element
        ds[index] = 0;
        SubSequence(index + 1, arr, ds, check, found);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        int[] arr = new int[size];
        int[] ds = new int[size];
        int[] found = new int[1];
        found[0] = 0;

        for (int i = 0; i < size; i++) {
            System.out.print("Enter the Element: ");
            arr[i] = input.nextInt();
        }

        System.out.print("\nOriginal Array: ");
        for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");

        System.out.print("\n\nEnter the number to check: ");
        int check = input.nextInt();

        SubSequence(0, arr, ds, check, found);    
        if (found[0] == 0) System.err.println("No Pairs Found...");  
    }
}