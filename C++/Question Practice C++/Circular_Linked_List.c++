#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void InsertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
    }

    void InsertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        cout<<"\nInserted New Node with value "<<newNode->data<<endl;
    }

    void DeleteAtBeginning() {
        if (head == nullptr) {
            cout<<"\nList is Empty"<<endl;
            return;
        }

        if (head->next == head) {
            cout<<"\nDeleted Head Node with value "<<head->data<<endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = head->next;
        head = head->next;
        cout<<"\nDeleted Head Node with value "<<temp->data<<endl;
        delete temp;
    }

    void DeleteAtEnd() {
        if (head == nullptr) {
            cout << "\nList is Empty" << endl;
            return;
        }

        if (head->next == head) {
            cout<<"\nDeleted Head Node with value "<<head->data<<endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) temp = temp->next;

        Node* del = temp->next;
        temp->next = head;
        cout<<"\nDeleted Last Node with value "<<del->data<<endl;
        delete del;
    }

    void Display() {
        if (head == nullptr) {
            cout<<"List is Empty"<<endl;
            return;
        }

        Node* temp = head;
        do {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } while (temp != head);
        cout<<"(back to head)"<<endl;
    }
};

int main() {
    LinkedList l1;

    cout<<"Circular Linked List Operations:\n1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Display\n6. Exit"<<endl;
    while (1) {
        int choice, elem;
        cout<<"\nEnter Linked List Function: ";
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter the Element: ";
            cin>>elem;
            l1.InsertAtBeginning(elem);
        } else if (choice == 2) {
            cout<<"Enter the Element: ";
            cin>>elem;
            l1.InsertAtEnd(elem);
        }
        else if (choice == 3) l1.DeleteAtBeginning();
        else if (choice == 4) l1.DeleteAtEnd();
        else if (choice == 5) l1.Display();
        else if (choice == 6) break;
        else cout<<"\nInvalid Choice"<<endl;
    }

    return 0;
}