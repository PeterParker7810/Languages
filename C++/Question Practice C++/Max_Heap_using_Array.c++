#include <iostream>
using namespace std;

class Heap {
public:
    int *arr, size, capacity;

    Heap(int cap) {
        capacity = cap;
        int* arr = new int[capacity];
        size = 0;
    }

    void insert(int val) {
        if (size == capacity) cout<<"Heap is full"<<endl;
        else {
            arr[size] = val;
            int i = size++;
            while (i != 0 && arr[(i-1)/2] < arr[i]) {
                swap(arr[i], arr[(i-1)/2]);
                i = (i-1)/2;
            }
        }
    }

    void deleteMax() {
        if (size <= 0) cout<<"Heap is empty"<<endl;
        else if (size == 1) size--;
        else {
            arr[0] = arr[(size--) - 1];
            heapify(0);
        }
    }

    void heapify(int i) {
        int max = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if (left < size && arr[left] > arr[max]) max = left;
        if (right < size && arr[right] > arr[max]) max = right;

        if (max != i) {
            swap(arr[i], arr[max]);
            heapify(max);
        }
    }

    int findMax() {
        if (size == 0) {
            cout<<"Heap is empty"<<endl;
            return -1;
        } return arr[0];
    }

    int findMin() {
        if (size == 0) {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int min = arr[size/2]; 
        for (int i = size/2 + 1; i < size; i++) if (arr[i] < min) min = arr[i];
        return min;
    }

    void display() {
        if (size == 0) cout<<"Heap is empty"<<endl;
        else {
            for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    int cap;
    cout<<"Enter the size of Heap: ";
    cin>>cap;
    Heap heap(cap);

    cout<<"\nHeap Functions:\n1. Insert\n2. Delete Max\n3. Find Max\n4. Find Min\n5. Display"<<endl;
    while (true) {
        int choice, elem;
        cout<<"\nEnter Heap Operation: ";
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter element to insert: ";
            cin>>elem;
            heap.insert(elem);
        } 
        else if (choice == 2) heap.deleteMax();
        else if (choice == 3) cout<<"Max: "<<heap.findMax()<<endl; 
        else if (choice == 4) cout<<"Min: "<<heap.findMin()<<endl;
        else if (choice == 5) heap.display();
        else cout<<"Invalid choice"<<endl;
    }
    return 0;
}