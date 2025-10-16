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
    Node head;
    int count, size;

    LinkedList(int size) {
        this.head = null;
        this.count = 0;
        this.size = size;
    }

    void Push(int val){
        if (isFull()) System.out.println("\nStack is full");
        else {
            Node newNode = new Node(val);
            if (head == null) head = newNode;
            else {
                newNode.next = head;
                head = newNode;
            } System.out.println("\nPushed " + val);
            count++;
        } 
    }

    void Pop(){
        if (isEmpty()) System.out.println("\nStack is empty");
        else {
            System.out.println("\nPopped " + head.data);
            head = head.next;
            count--;
        }
    }

    boolean isFull() {return count == size;}
    boolean isEmpty() {return head == null;}

    void Display(){
        if (isEmpty()) {
            System.out.println("\nStack is empty");
            return;
        }
        Node temp = head;
        System.out.println("\nDisplaying Stack Items:");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } System.out.println();
    }
}

public class Stack_using_Linked_Lists{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the no of Elements: ");
        LinkedList stack = new LinkedList(input.nextInt());

        System.out.println("\nStack Functions:\n1. Push\n2. Pop\n3. isFull\n4. isEmpty\n5. Display");
        while (true) { 
            System.out.print("\nEnter Stack Function: ");
            int choice = input.nextInt();

            if (choice == 1){
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                stack.Push(elem);
            } else if (choice == 2) stack.Pop();
            else if (choice == 3) System.out.println("\nStack is " + (stack.isFull() ? "full" : "not full"));
            else if (choice == 4) System.out.println("\nStack is " + (stack.isEmpty() ? "empty" : "not empty"));
            else if (choice == 5) stack.Display();
            else System.out.println("\nInvalid choice");
        }
    }
}