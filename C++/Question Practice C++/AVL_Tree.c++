#include<iostream>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {return node ? node->height : 0;}

int getBalance(Node* node) {return node ? getHeight(node->left) - getHeight(node->right) : 0;}

void updateHeight(Node* node) {if (node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* y) { 
    Node* x = y->right; 
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

class AVL {
public:
    Node* root;
    AVL() : root(nullptr) {}

    Node* Balancing(Node* node) {
        if (!node) return nullptr;

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);      
        if (balance > 1 && getBalance(node->left) < 0) {                               
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);       
        if (balance < -1 && getBalance(node->right) > 0) {                               
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* Insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data) node->left = Insert(node->left, val);
        else if (val > node->data) node->right = Insert(node->right, val);
        else return node; 

        return Balancing(node);
    }

    void Insert(int val) {
        root = Insert(root, val);
        cout<<"Inserted "<<val<<endl;
    }

    Node* FindMin(Node* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* Delete(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data) node->left = Delete(node->left, val);
        else if (val > node->data) node->right = Delete(node->right, val);
        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Node* temp = FindMin(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, temp->data);
            }
        }

        return Balancing(node);
    }

    void Delete(int val) {
        root = Delete(root, val);
        cout<<"Deleted "<<val<<endl;
    }

    bool Search(Node* node, int val) const {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return Search(node->left, val);
        return Search(node->right, val);
    }

    bool Search(int val) const { return Search(root, val); }

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

    int Height() const {return getHeight(root);}
};

int main(){
    AVL tree;
    cout<<"AVL Tree Operations:\n1. Insert\n2. Search\n3. Delete\n4. Height\n5. Inorder\n6. Preorder\n7. Postorder"<<endl;
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
            cout<<val<<(tree.Search(val) ? " Found." : " Not Found.")<<endl;
        } else if (choice == 3) {
            cout<<"Enter value to Delete: ";
            cin>>val;
            tree.Delete(val);
        } else if (choice == 4) cout<<"Height of the tree: "<<tree.Height()<<endl;
        else if (choice == 5) tree.Inorder();
        else if (choice == 6) tree.Preorder();
        else if (choice == 7) tree.Postorder();
        else cout<<"Invalid choice. Try again."<<endl;
    }
    return 0;
}