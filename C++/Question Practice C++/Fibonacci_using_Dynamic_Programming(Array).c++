#include<iostream>
using namespace std;

int Fibonacci(int lim, int dp[]){
    if (lim <= 1) {
        dp[lim] = lim;
        return lim;
    }
    if (dp[lim] != -1) return dp[lim];
    dp[lim] = Fibonacci(lim - 1, dp) + Fibonacci(lim - 2, dp);
    return dp[lim];
}

int main(){
    int limit;
    cout<<"Enter the Limit: ";
    cin>>limit;

    int* dp = new int[limit+1];
    for (int i = 0; i <= limit; i++) dp[i] = -1;
    cout<<"Fibonacci Sequence: ";
    for(int i = 0; i < limit; i++) cout<<Fibonacci(i, dp)<<" ";

    delete[] dp;
    return 0;
}