import java.util.Scanner;
public class Binary_Search{
    public static int BinarySearch(int[] arr, int find){
        int start = 0, end = arr.length-1;
        while (start <= end){
            int mid = start + (end-start)/2;
            if (arr[mid] == find) return mid;
            else if (arr[mid] < find) start = mid+1;
            else end = mid-1;
        } return -1;
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

        System.out.print("Enter the Element to Find: ");
        int find = input.nextInt();

        int found = BinarySearch(arr, find);
        if (found == -1) System.out.println("Element not found");
        else System.out.println("Element found at index: " + found);
    }
}