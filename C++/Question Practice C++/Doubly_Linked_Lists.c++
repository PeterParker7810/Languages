#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList{
    public:
        Node* head;

        LinkedList() : head(nullptr) {}

        void InsertAtBeginning(int val){
            Node* newNode = new Node(val);

            if (head == nullptr){
                head = newNode;
                cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
                return;
            }

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
        }

        void InsertAtEnd(int val){
            Node* newNode = new Node(val);
            if (head == nullptr){
                head = newNode;
                cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            cout<<"\nInserted New Node with value "<<newNode->data<<endl;
        }

        void DeleteAtBeginning(){
            if (head == nullptr){
                cout<<"\nList is Empty"<<endl;
                return;
            }
            Node* temp = head;
            cout<<"Deleted Head Node with value "<<temp->data<<endl;
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
        }

        void DeleteAtEnd(){
            if (head == nullptr){
                cout<<"\nList is Empty"<<endl;
                return;
            }

            if (head->next == nullptr){
                cout<<"\nDeleted Head Node with value "<<head->data<<endl;
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while (temp->next->next != nullptr) temp = temp->next;
            cout<<"\nDeleted Last Node with value "<<temp->next->data<<endl;
            delete temp->next;
            temp->next = nullptr;
        }

        void Display(){
            Node* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<" <-> ";
                temp = temp->next;
            } cout<<"nullptr"<<endl;
        }
};

int main(){
    LinkedList l1;

    cout<<"Linked List Functions:\n1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Display"<<endl;
    while (1){
        int choice, elem;
        cout<<"\nEnter Linked List Function: ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter the Element: ";
            cin>>elem;
            l1.InsertAtBeginning(elem);
        } else if (choice == 2){
            cout<<"Enter the Element: ";
            cin>>elem;
            l1.InsertAtEnd(elem);
        } else if (choice == 3) l1.DeleteAtBeginning();
        else if (choice == 4) l1.DeleteAtEnd();
        else if (choice == 5) l1.Display();
        else cout<<"\nInvalid Choice"<<endl;
    }
    
    return 0;
}