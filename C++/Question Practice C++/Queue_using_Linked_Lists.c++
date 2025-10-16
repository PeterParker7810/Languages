#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    public:
        Node *head, *tail;
        int count, size;
        LinkedList(int siz) : head(nullptr), tail(nullptr), count(0), size(siz) {}

        void Enqueue(int val){
            if (isFull()) cout<<"Queue is Full"<<endl;
            else {
                Node* newNode = new Node(val);
                if (head == nullptr) head = tail = newNode;
                else {
                    tail->next = newNode;
                    tail = newNode;
                }
                cout<<"Enqueued "<<val<<endl;
                count++;
            }
        }

        void Dequeue(){
            if (isEmpty()) cout<<"Queue is Empty"<<endl;
            else {
                Node* temp = head;
                head = head->next;
                if (head == nullptr) tail = nullptr;
                cout<<"Dequeued "<<temp->data<<endl;
                delete temp;
                count--;
            }
        }

        bool isFull() const {return count == size;}
        bool isEmpty() const {return head == nullptr;}

        void Display(){
            if (head == nullptr) cout<<"Queue is Empty"<<endl;
            else{
                cout<<"Displaying Queue Elements:"<<endl;
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
    cout<<"Enter the size of Queue: ";
    cin>>size;

    LinkedList queue(size);
    cout<<"Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display"<<endl;
    while(1){
        cout<<"\nEnter Queue Function: ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter the Element: ";
            cin>>elem;
            queue.Enqueue(elem);
        } else if (choice == 2) queue.Dequeue();
        else if (choice == 3) cout<<(queue.isFull() ? "Queue is Full" : "Queue is not Full")<<endl;
        else if (choice == 4) cout<<(queue.isEmpty() ? "Queue is Empty" : "Queue is not Empty")<<endl;
        else if (choice == 5) cout<<"Number of Items in Queue are "<<queue.count<<endl;
        else if (choice == 6) queue.Display();
        else cout<<"Invalid Choice"<<endl;
    }
    
    return 0;
}