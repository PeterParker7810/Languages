#include<iostream>
#include<vector>
using namespace std;

int Fibonacci(int lim, vector<int>& dp){
    if (lim <= 1) return lim;
    if (dp[lim] != -1) return dp[lim];
    dp[lim] = Fibonacci(lim - 1, dp) + Fibonacci(lim - 2, dp);
    return dp[lim];
}

int main(){
    int limit;
    cout<<"Enter the Limit: ";
    cin>>limit;
    vector<int> dp(limit + 1, -1);

    cout<<"Fibonacci Sequence: ";
    for (int i = 0; i < limit; i++) cout<<Fibonacci(i, dp)<<" ";
    
    return 0;
}