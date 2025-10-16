#include<iostream>
using namespace std;

void findMinMax(int* arr, int start, int end, int* min, int* max) {
    if (start == end) {
        if (arr[start] < *min) *min = arr[start];
        if (arr[start] > *max) *max = arr[start];
        return;
    }

    if (start+1 == end) {
        if (arr[start] < arr[end]) {
            if (arr[start] < *min) *min = arr[start];
            if (arr[end] > *max) *max = arr[end];
        } else {
            if (arr[end] < *min) *min = arr[end];
            if (arr[start] > *max) *max = arr[start];
        } return;
    }

    int mid = (start+end)/2;
    findMinMax(arr, start, mid, min, max);
    findMinMax(arr, mid + 1, end, min, max);
}

int main(){
    int size, min, max;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout<<"Enter the Element: ";
        cin>>arr[i];
    }

    min, max = arr[0];
    findMinMax(arr, 0, size-1, &min, &max);
    cout<<"\nMin Element: "<<min<<endl;
    cout<<"Max Element: "<<max<<endl;
    
    return 0;
}