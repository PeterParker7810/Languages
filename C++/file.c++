#include<iostream>
#include<vector>
using namespace std;

void FrogJump(vector<int> arr, vector<int>& solutions, int index, int energy){
    if (index >= arr.size() - 1) {
        solutions.push_back(energy);
        return;
    }

    // Jump to the next stair
    if (index + 1 < arr.size()) FrogJump(arr, solutions, index + 1, energy + abs(arr[index] - arr[index + 1]));

    // Jump to the stair after next
    if (index + 2 < arr.size()) FrogJump(arr, solutions, index + 2, energy + abs(arr[index] - arr[index + 2]));
}

int main(){
    int size;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    vector<int> arr(size);
    vector<int> solutions;
    for (int i = 0; i < size; i++) {
        cout<<"Enter Element "<<i+1<<": ";
        cin>>arr[i];
    }

    cout<<"\nElements in the array are:"<<endl;
    for (int i = 0; i < size; i++) cout<<arr[i]<<" ";
    cout<<endl;

    FrogJump(arr, solutions, 0, 0);
    cout<<"\nPossible energy values for different paths are:"<<endl;
    for (int val : solutions) cout<<val<<" ";
    
    return 0;
}