import java.util.Scanner;
class Node {
    int data;
    Node next, prev;

    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {this.head = null;}

    public void InsertAtBeginning(int val) {
        Node newNode = new Node(val);
        if (head != null) {
            newNode.next = head;
            head.prev = newNode;
        }
        head = newNode;
        System.out.println("\nInserted head node with value " + newNode.data);
    }

    public void InsertAtEnd(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
            System.out.println("\nInserted head node with value " + newNode.data);
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
        newNode.prev = temp;
        System.out.println("\nInserted new node with value " + newNode.data);
    }

    public void DeleteAtBeginning() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        System.out.println("\nDeleted node with value " + head.data);
        head = head.next;
        if (head != null) head.prev = null;
    }

    public void DeleteAtEnd() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        if (head.next == null) {
            System.out.println("\nDeleted node with value " + head.data);
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        System.out.println("\nDeleted node with value " + temp.data);
        temp.prev.next = null;
    }

    public void Display() {
        if (head == null) {
            System.out.println("\nList is empty");
            return;
        }
        Node temp = head;
        System.out.println();
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        } System.out.println("null");
    }
}

public class Doubly_Linked_Lists {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        LinkedList list = new LinkedList();

        System.out.println("Doubly Linked List Operations:\n1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Display");
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
