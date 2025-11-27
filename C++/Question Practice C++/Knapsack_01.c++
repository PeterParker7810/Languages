#include<iostream>
#include<vector>
using namespace std;

int KnapSack(vector<int> &profits, vector<int> &weights, int capacity, int size) {
    vector<vector<int>> dp(size + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= size; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w], 
                    profits[i - 1] + dp[i - 1][w - weights[i - 1]]
                );
            } else dp[i][w] = dp[i - 1][w];    
        }
    } return dp[size][capacity];
}

int main() {
    int size, capacity;
    cout<<"Enter the no of elements: ";
    cin>>size;

    cout<<"Enter Knapsack capacity: ";
    cin>>capacity;

    vector<int> profits(size);
    vector<int> weights(size);
    for (int i = 0; i < size; i++) {
        cout<<"\nFor Element-"<<i+1<<endl;
        cout<<"Enter Profit: ";
        cin>>profits[i];
        cout<<"Enter Weight: ";
        cin>>weights[i];
    }

    int maxProfit = KnapSack(profits, weights, capacity, size);
    cout<<"\nMaximum Profit is: "<<maxProfit<<endl;

    return 0;
}