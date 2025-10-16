#include<iostream>
using namespace std;

void CountingSort(int arr[], int size, int last){
    int* count = new int[10]{};
    int* output = new int[size];

    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / last) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / last) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < size; i++) arr[i] = output[i];

    delete[] output;
    delete[] count;
}

void RadixSort(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] > max) max = arr[i];

    for (int last = 1; max / last > 0; last *= 10) CountingSort(arr, size, last);
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

    RadixSort(arr, size);
    cout<<"\nAfter Sorting:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
