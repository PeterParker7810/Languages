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
        if (size == capacity) {
            cout<<"Heap is full"<<endl;
            return;
        }
        arr[size] = val;
        int i = size++;
        while (i != 0 && arr[(i-1)/2] > arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void deleteMin() {
        if (size <= 0) cout<<"Heap is empty"<<endl;
        else if (size == 1) size--;
        else {
            arr[0] = arr[(size--) - 1];
            heapify(0);
        }
    }

    void heapify(int i) {
        int min = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if (left < size && arr[left] < arr[min]) min = left;
        if (right < size && arr[right] < arr[min]) min = right;
        if (min != i) {
            swap(arr[i], arr[min]);
            heapify(min);
        }
    }

    int findMin() {
        if (size == 0) {
            cout<<"Heap is empty"<<endl;
            return -1;
        } return arr[0];
    }

    int findMax() {
        if (size == 0) {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int max = arr[size/2]; 
        for (int i = size/2 + 1; i < size; i++) if (arr[i] > max) max = arr[i];
        return max;
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

    cout<<"\nHeap Functions:\n1. Insert\n2. Delete Min\n3. Find Min\n4. Find Max\n5. Display"<<endl;
    while (true) {
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