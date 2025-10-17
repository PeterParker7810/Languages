#include<iostream>
#include<vector>
using namespace std;

int main(){
    int limit;
    cout<<"Enter the Limit: ";
    cin>>limit;

    vector<int> dp(limit + 1, -1);
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i < limit; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout<<"Fibonacci Sequence: ";
    for(int i = 0; i < limit; i++) cout<<dp[i]<<" ";
  
    return 0;
}