#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        left = right = parent = nullptr;
    }
};

class Heap {
    Node* root;

    vector<Node*> getLevelOrder() {
        vector<Node*> nodes;
        if (!root) return nodes;

        nodes.push_back(root);
        for (size_t i = 0; i < nodes.size(); i++) {
            if (nodes[i]->left) nodes.push_back(nodes[i]->left);
            if (nodes[i]->right) nodes.push_back(nodes[i]->right);
        } return nodes;
    }

    void insertNode(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        } else {
            vector<Node*> nodes = getLevelOrder();
            for (Node* node : nodes) {
                if (!node->left) {
                    node->left = newNode;
                    newNode->parent = node;
                    percolateUp(newNode);
                    return;
                } else if (!node->right) {
                    node->right = newNode;
                    newNode->parent = node;
                    percolateUp(newNode);
                    return;
                }
            }
        }
    }

    void percolateUp(Node* node) {
        while (node->parent && node->data < node->parent->data) {
            swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    void heapify(Node* node) {
        if (!node) return;

        Node* smallest = node;
        if (node->left && node->left->data < smallest->data) smallest = node->left;
        if (node->right && node->right->data < smallest->data) smallest = node->right;

        if (smallest != node) {
            swap(node->data, smallest->data);
            heapify(smallest);
        }
    }

    Node* getLastNode() {
        vector<Node*> nodes = getLevelOrder();
        return nodes.empty() ? nullptr : nodes.back();
    }

public:
    Heap() { root = nullptr;}

    void insert(int val) {insertNode(val);}

    void deleteMin() {
        if (!root) cout<<"Heap is empty"<<endl;
        else {
            Node* last = getLastNode();
            if (last == root) {
                delete root;
                root = nullptr;
                return;
            }
            root->data = last->data;

            if (last->parent->left == last) last->parent->left = nullptr;
            else last->parent->right = nullptr;

            delete last;
            heapify(root);
        }
    }

    int findMin() {
        if (!root) {
            cout<<"Heap is empty"<<endl;
            return -1;
        } return root->data;
    }

    int findMax() {
        vector<Node*> nodes = getLevelOrder();
        if (nodes.empty()) {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int maxVal = nodes[0]->data;
        for (Node* node : nodes) if (node->data > maxVal) maxVal = node->data;
        return maxVal;
    }

    void display() {
        if (!root) cout<<"Heap is empty"<<endl;
        else {
            vector<Node*> nodes = getLevelOrder();
            for (Node* node : nodes) cout<<node->data<<" ";
            cout<<endl;
        }
    }
};

int main() {
    Heap heap;
    cout<<"\nMin Heap Functions:\n1. Insert\n2. Delete Min\n3. Find Min\n4. Find Max\n5. Display"<<endl;

    while (1) {
        int choice, elem;
        cout<<"\nEnter Heap Operation: ";
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter element to insert: ";
            cin>>elem;
            heap.insert(elem);
        }
        else if (choice == 2) heap.deleteMin();
        else if (choice == 3) cout<<"Min: "<<heap.findMin()<<endl;
        else if (choice == 4) cout<<"Max: "<<heap.findMax()<<endl;
        else if (choice == 5) heap.display();
        else cout<<"Invalid choice"<<endl;
    }
    return 0;
}