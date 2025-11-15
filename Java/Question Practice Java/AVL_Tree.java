import java.util.Scanner;
class Node {
    int data, height;
    Node left, right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = null;
    }
}

class AVL {
    Node root;

    AVL() {root = null;}

    int getHeight(Node node) {return node != null ? node.height : 0;}

    int getBalance(Node node) {return node != null ? getHeight(node.left) - getHeight(node.right) : 0;}

    int Height() {return getHeight(root);}

    void updateHeight(Node node) {
        if (node != null) node.height = 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node leftRotate(Node y) {
        Node x = y.right;
        Node T2 = x.left;

        x.left = y;
        y.right = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node Balancing(Node node) {
        if (node == null) return null;

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node.left) >= 0) return rightRotate(node);
        if (balance > 1 && getBalance(node.left) < 0) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node.right) <= 0) return leftRotate(node);
        if (balance < -1 && getBalance(node.right) > 0) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    Node Insert(Node node, int val) {
        if (node == null) return new Node(val);

        if (val < node.data) node.left = Insert(node.left, val);
        else if (val > node.data) node.right = Insert(node.right, val);
        else return node;

        return Balancing(node);
    }

    void Insert(int val) {
        root = Insert(root, val);
        System.out.println("Inserted " + val);
    }

    Node FindMin(Node node) {
        while (node != null && node.left != null) node = node.left;
        return node;
    }

    Node Delete(Node node, int val) {
        if (node == null) return null;

        if (val < node.data) node.left = Delete(node.left, val);
        else if (val > node.data) node.right = Delete(node.right, val);
        else {
            if (node.left == null || node.right == null) {
                Node temp = (node.left != null) ? node.left : node.right;
                return temp;
            } else {
                Node temp = FindMin(node.right);
                node.data = temp.data;
                node.right = Delete(node.right, temp.data);
            }
        }

        return Balancing(node);
    }

    void Delete(int val) {
        root = Delete(root, val);
        System.out.println("Deleted " + val);
    }

    boolean Search(Node node, int val) {
        if (node == null) return false;
        if (node.data == val) return true;
        if (val < node.data) return Search(node.left, val);
        return Search(node.right, val);
    }

    boolean Search(int val) {return Search(root, val);}

    void Inorder(Node node) {
        if (node == null) return;
        Inorder(node.left);
        System.out.print(node.data + " ");
        Inorder(node.right);
    }

    void Preorder(Node node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        Preorder(node.left);
        Preorder(node.right);
    }

    void Postorder(Node node) {
        if (node == null) return;
        Postorder(node.left);
        Postorder(node.right);
        System.out.print(node.data + " ");
    }

    void Inorder() {
        System.out.print("Inorder: ");
        Inorder(root);
        System.out.println();
    }

    void Preorder() {
        System.out.print("Preorder: ");
        Preorder(root);
        System.out.println();
    }

    void Postorder() {
        System.out.print("Postorder: ");
        Postorder(root);
        System.out.println();
    }
}

public class AVL_Tree {
    public static void main(String[] args) {
        AVL tree = new AVL();
        Scanner input = new Scanner(System.in);
        System.out.println("AVL Tree Operations:\n1. Insert\n2. Search\n3. Delete\n4. Height\n5. Inorder\n6. Preorder\n7. Postorder");

        while (true) {
            System.out.print("\nEnter Tree Operation: ");
            int choice = input.nextInt();
            int val;

            if (choice == 1) {
                System.out.print("Enter value to Insert: ");
                val = input.nextInt();
                tree.Insert(val);
            } else if (choice == 2) {
                System.out.print("Enter value to Search: ");
                val = input.nextInt();
                System.out.println(val + (tree.Search(val) ? " Found." : " Not Found."));
            } else if (choice == 3) {
                System.out.print("Enter value to Delete: ");
                val = input.nextInt();
                tree.Delete(val);
            } else if (choice == 4) System.out.println("Height of the tree: " + tree.Height());
            else if (choice == 5) tree.Inorder();
            else if (choice == 6) tree.Preorder();
            else if (choice == 7) tree.Postorder();
            else System.out.println("Invalid choice. Try again.");
        }
    }
}