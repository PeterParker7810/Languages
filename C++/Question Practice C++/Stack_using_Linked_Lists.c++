#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    int count, size;
        LinkedList(int siz) : head(nullptr), count(0), size(siz) {}

        void Push(int val){
            if (isFull()) cout<<"Stack is Full"<<endl;
            else {
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
                count++;
                cout<<"Pushed "<<val<<endl;
            }
        }

        void Pop(){
            if (isEmpty()) cout<<"Stack is Empty"<<endl;
            else {
                Node* temp = head;
                head = head->next;
                cout<<"Popped "<<temp->data<<endl;
                delete temp;
                count--;
            }
        }

        bool isFull() const {return count == size;}
        bool isEmpty() const {return head == nullptr;}

        void Display(){
            if (isEmpty()) cout<<"Stack is Empty"<<endl;
            else {
                cout<<"Displaying Stack Elements:"<<endl;
                Node* temp = head;
                while (temp != nullptr){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                } cout<<endl;
            }
        }
};

int main(){
    int size, choice, elem;
    cout<<"Enter the size of Stack: ";
    cin>>size;

    LinkedList stack(size);
    cout<<"\nStack Functions:\n1. Push\n2. Pop\n3. isFull\n4. isEmpty\n5. Count\n6. Display"<<endl;

    while (1){
        cout<<"\nEnter Stack Function: ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter the Element: ";
            cin>>elem;
            stack.Push(elem);
        } else if (choice == 2) stack.Pop();
        else if (choice == 3) cout<<(stack.isFull() ? "Stack is Full" : "Stack is not Full")<<endl;
        else if (choice == 4) cout<<(stack.isEmpty() ? "Stack is Empty" : "Stack is not Empty")<<endl;
        else if (choice == 5) cout<<"Number of Items in Stack are "<<stack.count<<endl;
        else if (choice == 6) stack.Display();
        else cout<<"Invalid Choice"<<endl;
    }

    return 0;
}