#include<iostream>
using namespace std;

int main(){
    int limit,arr[100];
    cout<<"Enter the no of elements: ";
    cin>>limit;

    for (int i = 0; i < limit; i++){
        cout<<"Enter the Number: ";
        cin>>arr[i];
    }

    // Printing Original Array
    cout<<"\nOriginal Array:"<<endl;
    for (int i = 0; i < limit; i++){
        cout<<arr[i]<<" ";
    }

    // Swapping Elements
    int temp = 0;
    for (int i = 0; i < int(limit/2); i++){
        int temp1 = arr[temp];
        arr[temp] = arr[temp+1];
        arr[temp+1] = temp1;
        temp += 2;
    } 

    cout<<"\nModified Array:"<<endl;
    for (int i = 0; i < limit; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
