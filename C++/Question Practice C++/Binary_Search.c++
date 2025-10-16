#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int find){
    int start = 0, end = size-1;

    while (start <= end){
        int mid = start + (end-start)/2;
        if (arr[mid] == find) return mid;
        else if (arr[mid] < find) start = mid+1;
        else end = mid-1;
    } return -1;
}

int main(){
    int size, find;
    cout<<"Enter the Number of Elements: ";
    cin>>size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++){
        cout<<"Enter the Element: ";
        cin>>arr[i];
    }

    cout<<"\nEnter the Element to Find: ";
    cin>>find;
    int result = BinarySearch(arr, size, find);

    if (result == -1) cout<<"Element Not Found";
    else cout<<"Element Found at Index: "<<result;

    return 0;
}