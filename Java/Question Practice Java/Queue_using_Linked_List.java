import java.util.Scanner;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList{
    Node head, tail;
    int count, size;

    LinkedList(int size) {
        this.head = null;
        this.tail = null;
        this.count = 0;
        this.size = size;
    }

    void Enqueue(int val){
        if (isFull()) System.out.println("\nQueue is full");
        else {
            Node newNode = new Node(val);
            if (head == null) head = tail = newNode;
            else {
                tail.next = newNode;
                tail = newNode;
            } System.out.println("\nEnqueued " + val);
            count++;
        } 
    }

    void Dequeue(){
        if (isEmpty()) System.out.println("\nQueue is empty");
        else {
            System.out.println("\nDequeued " + head.data);
            head = head.next;
            if (head == null) tail = null;
            count--;
        }
    }

    boolean isFull() {return count == size;}
    boolean isEmpty() {return head == null;}

    void Display(){
        if (isEmpty()) {
            System.out.println("\nQueue is empty");
            return;
        }
        Node temp = head;
        System.out.println("\nDisplaying Queue Items:");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } System.out.println();
    }
}

public class Queue_using_Linked_List{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the no of Elements: ");
        LinkedList queue = new LinkedList(input.nextInt());

        System.out.println("\nQueue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Display");
        while (true) { 
            System.out.print("\nEnter Queue Function: ");
            int choice = input.nextInt();

            if (choice == 1){
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                queue.Enqueue(elem);
            } else if (choice == 2) queue.Dequeue();
            else if (choice == 3) System.out.println("\nQueue is " + (queue.isFull() ? "full" : "not full"));
            else if (choice == 4) System.out.println("\nQueue is " + (queue.isEmpty() ? "empty" : "not empty"));
            else if (choice == 5) queue.Display();
            else System.out.println("\nInvalid choice");
        }
    }
}