import java.util.Scanner;

public class Circular_Queue {
    static int front = -1, rear = -1;

    public static void Enqueue(int[] queue, int size, int elem) {
        if ((rear + 1) % size == front) System.out.println("\nQueue Overflow");
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % size;
            queue[rear] = elem;
            System.out.println("\nEnqueued " + elem);
        }
    }

    public static void Dequeue(int[] queue, int size) {
        if (front == -1) System.out.println("\nQueue Underflow");
        else {
            System.out.println("\nDequeued " + queue[front]);
            if (front == rear) front = rear = -1;
            else front = (front + 1) % size; 
        }
    }

    public static void Display(int[] queue, int size) {
        if (front == -1) System.out.println("\nQueue is Empty");
        else {
            System.out.println("\nDisplaying Circular Queue Elements:");
            int i = front;
            while (i != rear) {
                System.out.print(queue[i] + " ");
                i = (i + 1) % size;
            } System.out.println(queue[rear]);
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();
        int[] queue = new int[size];

        System.out.println("\nCircular Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display\n0. Exit");

        while (true) {
            System.out.print("\nEnter Queue Function: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                Enqueue(queue, size, elem);
            } else if (choice == 2) Dequeue(queue, size);
            else if (choice == 3) System.out.println((rear + 1) % size == front ? "\nQueue is Full" : "\nQueue is Not Full");
            else if (choice == 4) System.out.println(front == -1 ? "\nQueue is Empty" : "\nQueue is Not Empty");
            else if (choice == 5) {
                int count;
                if (front == -1) count = 0;
                else if (rear >= front) count = rear - front + 1;
                else count = size - front + rear + 1;
                System.out.println("\nNo of items in Queue are " + count);
            } else if (choice == 6) Display(queue, size);
            else System.out.println("\nInvalid Choice");
        }
    }
}