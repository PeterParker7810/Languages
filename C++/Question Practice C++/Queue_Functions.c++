#include<iostream>
#include<deque>
using namespace std;

void Enqueue(deque<int> &que, int elem, int size){
    if (que.size() < size){
        que.push_back(elem);
        cout<<"\nEnqueued "<<elem<<endl;
    } else cout<<"\nQueue Overflow"<<endl;
}

void Dequeue(deque<int> &que){
    if (!que.empty()){
        cout<<"\nDequeued "<<que.front()<<endl;
        que.pop_front();
    } else cout<<"\nQueue Underflow"<<endl;
}

void Display(deque<int> que){
    cout<<"\nDisplaying Queue Elements:"<<endl;
    for (int i = 0; i < que.size(); i++) cout<<que[i]<<" ";
    cout<<endl;
}

int main(){
    deque <int> queue;
    int size;
    cout<<"Enter the size of Queue: ";
    cin>>size;

    cout<<"Queue Functions:\n1. enqueue\n2. dequeue\n3. isFull\n4. isEmpty\n5. count\n6. display"<<endl;
    while (1){
        int choice;
        cout<<"\nEnter Queue Function: ";
        cin>>choice;

        if (choice == 1){
            int elem;
            cout<<"Enter the Element: ";
            cin>>elem;
            Enqueue(queue, elem, size);
        } else if (choice == 2) Dequeue(queue);
        else if (choice == 3) cout<<(queue.size() < size ? "\nQueue is not Full" : "\nQueue is Full")<<endl;
        else if (choice == 4) cout<<(queue.empty() ? "\nQueue is Empty" : "\nQueue is not Empty")<<endl;
        else if (choice == 5) cout<<"\nNumber of items in Queue is "<<queue.size()<<endl;
        else if (choice == 6) Display(queue);
        else cout<<"\nInvalid Choice"<<endl;       
    }
    
    return 0;
}