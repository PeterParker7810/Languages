#include<iostream>
using namespace std;

int Partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if (arr[j] < pivot) swap(arr[++i], arr[j]);  
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void QuickSort(int arr[], int start, int end){
    if (start < end){
        int part = Partition(arr, start, end);

        QuickSort(arr, start, part-1);
        QuickSort(arr, part+1, end);
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
    
    cout<<"Before Sorting:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    QuickSort(arr, 0, size-1);
    cout<<"After Sorting:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;

    delete[] arr; 
    
    return 0;
}