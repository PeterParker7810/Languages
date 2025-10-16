#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void InsertAtBeginning(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            cout<<"\nInserted Head Node with value "<<newNode->data<<endl;
        }

        void InsertAtEnd(int val){
            Node* newNode = new Node(val);
            if (head == nullptr){
                head = newNode;
                cout<<"\nInserted Head Node with Value "<<newNode->data<<endl;
                return;
            } 

            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
            cout<<"\nInserted new Node with Value "<<newNode->data<<endl;
        }

        void DeleteAtBeginning(){
            if (head == nullptr){
                cout<<"\nList is Empty"<<endl;
                return;
            }
            Node* temp = head;
            cout<<"Deleted Head Node with value "<<temp->data<<endl;
            head = head->next;
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
            Node* toDelete = temp->next;
            temp->next = nullptr;
            cout<<"\nDeleted Node with value "<<toDelete->data<<endl;
            delete toDelete;
        }

        void Display(){
            Node* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"nullptr"<<endl;
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