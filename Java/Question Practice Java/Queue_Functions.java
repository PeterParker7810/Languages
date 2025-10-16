import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Queue_Functions{
    public static void Enqueue(Queue<Integer> queue, int size, int elem) {
        if (queue.size() < size) {
            queue.add(elem);
            System.out.println("\nEnqueued " + elem);
        } else System.out.println("\nQueue Overflow");
    }

    public static void Dequeue(Queue<Integer> queue) {
        if (!queue.isEmpty()) {
            int elem = queue.poll();
            System.out.println("\nDequeued " + elem);
        } else System.out.println("\nQueue Underflow");
    }

    public static void Display(Queue<Integer> queue) {
        if (!queue.isEmpty()) {
            System.out.println("\nDisplaying Queue Elements:");
            for (int i = 0; i < queue.size(); i++) System.out.print(queue.toArray()[i] + " ");
            System.out.println(); 
        } else System.out.println("\nQueue is Empty");
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter the no of Elements: ");
        int size = input.nextInt();

        System.out.println("\nQueue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display");
        while (true){
            System.out.print("\nEnter Queue Function: ");
            int choice = input.nextInt();

            if (choice == 1){
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                Enqueue(queue, size, elem);
            } else if (choice == 2) Dequeue(queue);
            else if (choice == 3) System.out.println(queue.size() == size ? "\nQueue is Full" : "\nQueue is not Full");
            else if (choice == 4) System.out.println(queue.isEmpty() ? "\nQueue is Empty" : "\nQueue is not Empty");
            else if (choice == 5) System.out.println("No of items in Queue are " + queue.size());
            else if (choice == 6) Display(queue);
            else System.out.println("Invalid Choice");
        }
    }
}