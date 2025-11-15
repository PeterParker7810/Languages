import java.util.Scanner;
class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BST {
    Node root;

    BST() {root = null;}

    void insert(int val) {
        root = insertRec(root, val);
        System.out.println("Inserted " + val);
    }

    Node insertRec(Node root, int val) {
        if (root == null) return new Node(val);
        else {
            if (val < root.data) root.left = insertRec(root.left, val);
            else if (val > root.data) root.right = insertRec(root.right, val);
            return root;
        }
    }

    void inorder() {
        System.out.print("Inorder: ");
        inorderRec(root);
        System.out.println();
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }

    void preorder() {
        System.out.print("Preorder: ");
        preorderRec(root);
        System.out.println();
    }

    void preorderRec(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }

    void postorder() {
        System.out.print("Postorder: ");
        postorderRec(root);
        System.out.println();
    }

    void postorderRec(Node root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.data + " ");
        }
    }

    boolean search(int key) {return searchRec(root, key);}

    boolean searchRec(Node root, int key) {
        if (root == null) return false;
        else {
            if (key == root.data) return true;
            else if (key < root.data) return searchRec(root.left, key);
            else return searchRec(root.right, key);
        }
    }

    void delete(int val) {
        root = deleteRec(root, val);
        System.out.println("Deleted " + val + " (if existed)");
    }

    Node deleteRec(Node root, int key) {
        if (root == null) return root;
        
        if (key < root.data) root.left = deleteRec(root.left, key);
        else if (key > root.data) root.right = deleteRec(root.right, key);
        else {
            if (root.left == null) return root.right;
            else if (root.right == null) return root.left;
            else {
                root.data = minValue(root.right);
                root.right = deleteRec(root.right, root.data);
            }
        } return root;
    }

    int minValue(Node root) {
        int min = root.data;
        while (root.left != null) {
            root = root.left;
            min = root.data;
        } return min;
    }
}

public class Binary_Search_Tree {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BST tree = new BST();

        System.out.println("Binary Search Tree Operations:\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal");

        while (true) {
            System.out.print("\nEnter your choice: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter value to insert: ");
                int val = input.nextInt();
                tree.insert(val);
            } else if (choice == 2) {
                System.out.print("Enter value to delete: ");
                int val = input.nextInt();
                tree.delete(val);
            } else if (choice == 3) {
                System.out.print("Enter value to search: ");
                int key = input.nextInt();
                if (tree.search(key)) System.out.println("Value found in BST");
                else System.out.println("Value not found in BST");
            } else if (choice == 4) tree.inorder();
            else if (choice == 5) tree.preorder();
            else if (choice == 6) tree.postorder();
            else System.out.println("Invalid choice.");
        }
    }
}