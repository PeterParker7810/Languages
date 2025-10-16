#include<iostream>
using namespace std;

void Enqueue(int* queue, int* front, int* rear, int size, int elem){
    if ((*rear + 1) % size == *front) cout<<"Queue is Full"<<endl;
    else {
        if (*front == -1) *front = 0;
        *rear = (*rear + 1) % size;
        queue[*rear] = elem;
        cout<<"Enqueued "<<elem<<endl;
    }
}

void Dequeue(int* queue, int* front, int* rear, int size){
    if (*front == -1) cout << "Queue is Empty" << endl;
    else {
        cout<<"Dequeued "<<queue[*front]<<endl;
        if (*front == *rear) *front = *rear = -1;
        else *front = (*front + 1) % size;
    }
}

void isFull(int front, int rear, int size){
    if ((rear + 1) % size == front) cout<<"Queue is Full"<<endl;
    else cout<<"Queue is not Full"<<endl;
}

void isEmpty(int front){
    if (front == -1) cout<<"Queue is Empty"<<endl;
    else cout<<"Queue is not Empty"<<endl;
}

void Display(int* queue, int front, int rear, int size){
    if (front == -1) cout<<"Queue is Empty"<<endl;
    else {
        cout<<"Displaying Queue Elements:"<<endl;
        int index = front;
        while (1) {
            cout<<queue[index]<<" ";
            if (index == rear) break;
            index = (index + 1) % size;
        } cout<<endl;
    }
}

int main(){
    int size, front = -1, rear = -1, choice, elem;
    cout<<"Enter the Number of Elements: ";
    cin>>size;

    int* queue = new int[size];
    cout<<"Circular Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display"<<endl;
    while (1){
        cout<<"\nEnter Queue Function: ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter Element to Enqueue: ";
            cin>>elem;
            Enqueue(queue, &front, &rear, size, elem);
        }
        else if (choice == 2) Dequeue(queue, &front, &rear, size);
        else if (choice == 3) isFull(front, rear, size);
        else if (choice == 4) isEmpty(front);
        else if (choice == 5) cout<<"Number of Elements in Queue are "<<((front == -1) ? 0 : ((rear - front + size) % size + 1))<<endl;
        else if (choice == 6) Display(queue, front, rear, size);
        else cout<<"Invalid Choice"<<endl;
    }
    return 0;
}