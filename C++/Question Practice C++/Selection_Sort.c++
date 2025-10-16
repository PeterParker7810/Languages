#include<iostream>
using namespace std;

void SelectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
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
    
    SelectionSort(arr, size);
    cout<<"After Sorting:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;

    delete[] arr; 
    
    return 0;
}