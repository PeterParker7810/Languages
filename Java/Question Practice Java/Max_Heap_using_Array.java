import java.util.Scanner;
class Heap {
    int[] arr;
    int size, capacity;

    Heap(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    void swap(int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    void heapify(int i) {
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[max]) max = left;
        if (right < size && arr[right] > arr[max]) max = right;

        if (max != i) {
            swap(i, max);
            heapify(max);
        }
    }

    void insert(int val) {
        if (size == capacity) {
            System.out.println("Heap is full");
            return;
        }
        arr[size] = val;
        int i = size++;
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(i, (i- 1)/2);
            i = (i-1)/2;
        }
    }

    void deleteMax() {
        if (size <= 0) System.out.println("Heap is empty");
        else if (size == 1) size--;
        else {
            arr[0] = arr[--size];
            heapify(0);
        }
    }

    int findMax() {
        if (size == 0) {
            System.out.println("Heap is empty");
            return -1;
        } return arr[0];
    }

    int findMin() {
        if (size == 0) {
            System.out.println("Heap is empty");
            return -1;
        }

        int min = arr[size/2];
        for (int i = size/2 + 1; i < size; i++) if (arr[i] < min) min = arr[i];
        return min;
    }

    void display() {
        if (size == 0) System.out.println("Heap is empty");
        else {
            for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");
            System.out.println();
        }
    }
}

public class Max_Heap_using_Array {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of Heap: ");
        int cap = input.nextInt();
        Heap heap = new Heap(cap);

        System.out.println("\nHeap Functions:\n1. Insert\n2. Delete Max\n3. Find Max\n4. Find Min\n5. Display");
        while (true) {
            System.out.print("\nEnter Heap Operation: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter element to insert: ");
                int elem = input.nextInt();
                heap.insert(elem);
            } 
            else if (choice == 2) heap.deleteMax();
            else if (choice == 3) System.out.println("Max: " + heap.findMax());
            else if (choice == 4) System.out.println("Min: " + heap.findMin());
            else if (choice == 5) heap.display();
            else System.out.println("Invalid choice");
        }
    }
}