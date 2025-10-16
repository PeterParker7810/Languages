#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    void Insert(Node*& node, int val) {
        if (!node) {
            node = new Node(val);
            return;
        } 
        if (val < node->data) Insert(node->left, val);
        else Insert(node->right, val);
    }

    void Insert(int val) {
        Insert(root, val);
        cout<<"Inserted "<<val<<endl;
    }

    bool Search(Node* node, int val) const {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return Search(node->left, val);
        else return Search(node->right, val);
    }

    bool Search(int val) const {return Search(root, val);}

    Node* FindMin(Node* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* Delete(Node*& node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = Delete(node->left, val);
        else if (val > node->data) node->right = Delete(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            Node* temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        } return node;
    }

    void Delete(int val) {
        root = Delete(root, val);
        cout<<"Deleted "<<val<<endl;
    }

    int Height(Node* node) {
        if (!node) return 0;
        return 1 + max(Height(node->left), Height(node->right));
    }

    void Inorder(Node* node) const {
        if (!node) return;
        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
    } 

    void Preorder(Node* node) const {
        if (!node) return;
        cout<<node->data<<" ";
        Preorder(node->left);
        Preorder(node->right);
    }

    void Postorder(Node* node) const {
        if (!node) return;
        Postorder(node->left);
        Postorder(node->right);
        cout<<node->data<<" ";
    }

    void Inorder() const {
        cout<<"Inorder: ";
        Inorder(root);
        cout<<endl;
    }

    void Preorder() const {
        cout<<"Preorder: ";
        Preorder(root);
        cout<<endl;
    }

    void Postorder() const {
        cout<<"Postorder: ";
        Postorder(root);
        cout<<endl;
    }
};

int main(){
    BST tree;

    cout<<"Binary Search Tree Operations:\n1. Insert\n2. Search\n3. Delete\n4. Height\n5. Inorder Traversal\n6. Preorder Traversal\n7. Postorder Traversal"<<endl;
    while (1) {
        int choice, val;
        cout<<"\nEnter Tree Operation: ";
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter value to Insert: ";
            cin>>val;
            tree.Insert(val);
        } else if (choice == 2) {
            cout<<"Enter value to Search: ";
            cin>>val;
            cout<<val<<(tree.Search(val) ? " Found in the tree." : " Not Found in the tree.")<<endl;
        } else if (choice == 3) {
            cout<<"Enter value to Delete: ";
            cin>>val;
            tree.Delete(val);
        } else if (choice == 4) cout<<"Height of the tree: "<<tree.Height(tree.root)<<endl;
        else if (choice == 5) tree.Inorder();
        else if (choice == 6) tree.Preorder();
        else if (choice == 7) tree.Postorder();
        else cout<<"Invalid choice. Please try again."<<endl;
    }

    return 0;
}