#include<iostream>
using namespace std;

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int curr = arr[i];
        int prev = i-1;
    
        while (prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
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

    InsertionSort(arr, size);
    cout<<"\nAfter Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
