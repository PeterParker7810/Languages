import java.util.*;
public class Median_of_two_sorted_arrays{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int limit1,limit2,limit3;
        int[] arr1 = new int[100];
        int[] arr2 = new int[100];
        int[] arr3 = new int[100];

        //Inputting Values for Array-1
        System.out.print("Enter no of elements for Array-1: ");
        limit1 = input.nextInt();

        System.out.println("For Array-1:");
        for (int i = 0; i < limit1; i++){
            System.out.print("Enter the element: ");
            arr1[i] = input.nextInt();
        }
        
        //Inputting Values for Array-2
        System.out.print("\nEnter no of elements for Array-2: ");
        limit2 = input.nextInt();

        System.out.println("For Array-2:");
        for (int i = 0; i < limit2; i++){
            System.out.print("Enter the element: ");
            arr2[i] = input.nextInt();
        }

        //Merging and Sorting Arrays
        limit3 = limit1 + limit2;

        System.out.println("\nElements for Array-1:");
        for (int i = 0; i < limit1; i++){
            System.out.print(arr1[i]);
            System.out.print(" ");
            arr3[i] = arr1[i];
        }
        
        System.out.println("\nElements for Array-2:");
        for (int i = 0; i < limit2; i++){
            System.out.print(arr2[i]);
            System.out.print(" ");
            arr3[i+limit1] = arr2[i];
        }

        int range = limit3;
        while (range > 0){      //Bubble Sort
            for (int i = 0; i <= range; i++){
                for (int j = i+1; j < range; j++){
                    if (arr3[i] > arr3[j]){
                        arr3[i] += arr3[j];
                        arr3[j] = arr3[i] - arr3[j];
                        arr3[i] -= arr3[j];
                    }
                }
            }
            range--;
        }

        System.out.println("\nElements for Merged Array:");
        for (int i = 0; i < limit3; i++){
            System.out.print(arr3[i]);
            System.out.print(" ");
        }

        System.out.print("\nMedian of Sorted Arrays: ");
        if ((limit3-1)%2 == 0){
            System.out.println(arr3[(limit3-1)/2]);
        }
        else{
            float avg = ((float)arr3[(limit3/2)-1] + (float)arr3[limit3/2])/2;
            System.out.println(avg);
        }
    }
}