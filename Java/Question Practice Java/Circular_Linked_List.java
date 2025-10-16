import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    Node head;

    public CircularLinkedList() {this.head = null;}

    public void InsertAtBeginning(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            Node temp = head;
            while (temp.next != head) temp = temp.next;
            newNode.next = head;
            temp.next = newNode;
            head = newNode;
        } System.out.println("\nInserted head node with value " + newNode.data);
    }

    public void InsertAtEnd(int val) {
        if (head == null) {
            InsertAtBeginning(val);
            return;
        }
        Node newNode = new Node(val);
        Node temp = head;
        while (temp.next != head) temp = temp.next;
        temp.next = newNode;
        newNode.next = head;
        System.out.println("\nInserted new node with value " + newNode.data);
    }

    public void DeleteAtBeginning() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        if (head.next == head) {
            System.out.println("\nDeleted node with value " + head.data);
            head = null;
            return;
        }
        Node temp = head;
        Node last = head;
        while (last.next != head) last = last.next;
        head = head.next;
        last.next = head;
        System.out.println("\nDeleted node with value " + temp.data);
    }

    public void DeleteAtEnd() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        if (head.next == head) {
            System.out.println("\nDeleted node with value " + head.data);
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != head) temp = temp.next;
        System.out.println("\nDeleted node with value " + temp.next.data);
        temp.next = head;
    }

    public void Display() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        Node temp = head;
        System.out.println();
        do {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        } while (temp != head);
        System.out.println("(head)");
    }
}

public class Circular_Linked_List {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        CircularLinkedList list = new CircularLinkedList();

        System.out.println("Circular Linked List Operations:\n1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Display");
        while (true) {
            System.out.print("\nEnter Linked List Function: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                list.InsertAtBeginning(elem);
            } else if (choice == 2) {
                System.out.print("Enter the Element: ");
                int elem = input.nextInt();
                list.InsertAtEnd(elem);
            } else if (choice == 3) list.DeleteAtBeginning();
            else if (choice == 4) list.DeleteAtEnd();
            else if (choice == 5) list.Display();
            else System.out.println("Invalid Choice");
        }
    }
}