import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Node {
    int data;
    Node left, right, parent;

    Node(int val) {
        data = val;
        left = right = parent = null;
    }
}

class Heap {
    private Node root;

    public Heap() {root = null;}

    private List<Node> getLevelOrder() {
        List<Node> nodes = new ArrayList<>();
        if (root == null) return nodes;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            nodes.add(curr);
            if (curr.left != null) queue.add(curr.left);
            if (curr.right != null) queue.add(curr.right);
        }
        return nodes;
    }

    private void insertNode(int val) {
        Node newNode = new Node(val);
        if (root == null) {
            root = newNode;
            return;
        } else {
            List<Node> nodes = getLevelOrder();
            for (Node node : nodes) {
                if (node.left == null) {
                    node.left = newNode;
                    newNode.parent = node;
                    percolateUp(newNode);
                    return;
                } else if (node.right == null) {
                    node.right = newNode;
                    newNode.parent = node;
                    percolateUp(newNode);
                    return;
                }
            }
        }
    }

    private void percolateUp(Node node) {
        while (node.parent != null && node.data < node.parent.data) {
            int temp = node.data;
            node.data = node.parent.data;
            node.parent.data = temp;
            node = node.parent;
        }
    }

    private void heapify(Node node) {
        if (node == null) return;

        Node smallest = node;
        if (node.left != null && node.left.data < smallest.data) smallest = node.left;
        if (node.right != null && node.right.data < smallest.data) smallest = node.right;

        if (smallest != node) {
            int temp = node.data;
            node.data = smallest.data;
            smallest.data = temp;
            heapify(smallest);
        }
    }

    private Node getLastNode() {
        List<Node> nodes = getLevelOrder();
        return nodes.isEmpty() ? null : nodes.get(nodes.size() - 1);
    }

    public void insert(int val) {insertNode(val);}

    public void deleteMin() {
        if (root == null) System.out.println("Heap is empty");
        else {
            Node last = getLastNode();
            if (last == root) {
                root = null;
                return;
            }
            root.data = last.data;

            if (last.parent.left == last) last.parent.left = null;
            else last.parent.right = null;

            heapify(root);
        }
    }

    public int findMin() {
        if (root == null) {
            System.out.println("Heap is empty");
            return -1;
        } return root.data;
    }

    public int findMax() {
        List<Node> nodes = getLevelOrder();
        if (nodes.isEmpty()) {
            System.out.println("Heap is empty");
            return -1;
        }
        int maxVal = nodes.get(0).data;
        for (Node node : nodes) if (node.data > maxVal) maxVal = node.data;
        return maxVal;
    }

    public void display() {
        if (root == null) System.out.println("Heap is empty");
        else {
            List<Node> nodes = getLevelOrder();
            for (Node node : nodes) System.out.print(node.data + " ");
            System.out.println();
        }
    }
}

public class Min_Heap_using_Binary_Tree {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Heap heap = new Heap();
        System.out.println("Min Heap Functions:\n1. Insert\n2. Delete Min\n3. Find Min\n4. Find Max\n5. Display");

        while (true) {
            System.out.print("\nEnter Heap Operation: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter element to insert: ");
                int elem = input.nextInt();
                heap.insert(elem);
            } else if (choice == 2) heap.deleteMin();
            else if (choice == 3) System.out.println("Min: " + heap.findMin());
            else if (choice == 4) System.out.println("Max: " + heap.findMax());
            else if (choice == 5) heap.display();
            else System.out.println("Invalid choice");
        }
    }
}