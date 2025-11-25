#include<iostream>
#include<vector>
using namespace std;

int KnapSack(vector<int> &profits, vector<int> &weights, int capacity, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w], 
                    profits[i - 1] + dp[i - 1][w - weights[i - 1]]
                );
            } else dp[i][w] = dp[i - 1][w];    
        }
    } return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter Knapsack capacity: ";
    cin>>capacity;

    vector<int> profits(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cout<<"\nFor Element-"<<i+1<<endl;
        cout<<"Profit: ";
        cin>>profits[i];
        cout<<"Weight: ";
        cin>>weights[i];
    }

    int maxProfit = KnapSack(profits, weights, capacity, n);
    cout<<"\nMaximum Profit is: "<<maxProfit<<endl;

    return 0;
}