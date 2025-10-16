#include<iostream>
using namespace std;

void Merge(int arr[], int start, int mid, int end){
    int sizeL = mid - start + 1;
    int sizeR = end - mid;

    int* Left = new int[sizeL];
    int* Right = new int[sizeR];

    for (int i = 0; i < sizeL; i++) Left[i] = arr[start + i];
    for (int i = 0; i < sizeR; i++) Right[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = start;
    while (i < sizeL && j < sizeR){
        if (Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        } else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < sizeL){
        arr[k] = Left[i];
        i++;
        k++;
    }  while (j < sizeR){
        arr[k] = Right[j];
        j++;
        k++;
    }

    delete[] Left;
    delete[] Right;
}

void MergeSort(int arr[], int start, int end){
    if (start < end){
        int mid = start + (end-start)/2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, start, mid, end);
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
    
    MergeSort(arr, 0, size-1);
    cout<<"After Sorting:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;

    delete[] arr; 
    
    return 0;
}