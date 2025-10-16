#include<iostream>
using namespace std;

void CountingSort(int arr[], int size){
    int max = arr[0], min = arr[0];
    
    for (int i = 1; i < size; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int* count = new int[max-min+1]{};
    for (int i = 0; i < size; i++) count[arr[i]-min]++;

    int index = 0;
    for (int i = 0; i < (max-min+1); i++){
        for (int j = 0; j < count[i]; j++) arr[index++] = i+min;
    } 

    delete[] count;
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

    CountingSort(arr, size);
    cout<<"\nAfter Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
