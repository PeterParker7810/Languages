#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int FrogJump(int index, vector<int>& arr, vector<int>& dp) {
    if (index == 0) return 0;
    if (dp[index] != -1) return dp[index];

    int left = FrogJump(index - 1, arr, dp) + abs(arr[index] - arr[index - 1]);
    int right = INT_MAX;
    if (index > 1) right = FrogJump(index - 2, arr, dp) + abs(arr[index] - arr[index - 2]);
    
    return dp[index] = min(left, right);
}

int main() {
    int size;
    cout<<"Enter the no of Elements: ";
    cin>>size;

    vector<int> arr(size);
    vector<int> dp(size, -1);
    for (int i = 0; i < size; i++) {
        cout<<"Enter the Element: ";
        cin>>arr[i];
    }

    cout<<"\nElements in the array are:"<<endl;
    for (int val : arr) cout<<val<<" ";
    cout<<endl;

    int result = FrogJump(size - 1, arr, dp);
    cout<<"\nMinimum Energy Required: "<<result<<endl;

    return 0;
}