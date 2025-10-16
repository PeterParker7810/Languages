#include<iostream>
using namespace std;

void Heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, size, largest);
    }
}

void HeapSort(int arr[], int size){
    for (int i = size/2 + 1; i >= 0; i--) Heapify(arr, size, i);

    for (int i = size-1; i > 0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

int main(){
    int size;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++){
        cout<<"Enter the Element: ";
        cin>>arr[i];
    }

    cout<<"\nBefore Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    HeapSort(arr, size);
    cout<<"\nAfter Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    return 0;
}