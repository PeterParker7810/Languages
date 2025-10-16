#include<iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);          
        }
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
    
    BubbleSort(arr, size);
    cout<<"After Sorting:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;

    delete[] arr; 
    
    return 0;
}