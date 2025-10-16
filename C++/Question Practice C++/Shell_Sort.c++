#include<iostream>
using namespace std;

void ShellSort(int arr[], int size){
    int gap = size/2;

    while (gap > 0){
        for (int i = gap; i < size; i++){
            int curr = arr[i];
            int prev = i - gap;

            while (prev >= 0 && arr[prev] > curr){
                arr[prev + gap] = arr[prev];
                prev -= gap;
            }
            arr[prev + gap] = curr;
        }
        gap /= 2;
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

    ShellSort(arr, size);
    cout<<"\nAfter Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
