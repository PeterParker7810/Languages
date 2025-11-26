#include<stdio.h>

int max(int a, int b) {return (a > b) ? a : b;}

int KnapSack(int profits[], int weights[], int size, int cap) {
    int dp[size + 1][cap + 1];
    for (int i = 0; i <= size; i++) for (int w = 0; w <= cap; w++) 
    if (i == 0 || w == 0) dp[i][w] = 0;

    for (int i = 1; i <= size; i++) {
        for (int w = 1; w <= cap; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], profits[i-1] + dp[i-1][w - weights[i-1]]);
            } else dp[i][w] = dp[i-1][w];
        }
    } return dp[size][cap];
}

int main(){
    int size, capacity;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    printf("Enter the capacity of Knapsack: ");
    scanf("%d", &capacity);
    
    int profits[size], weights[size];
    for (int i = 0; i < size; i++) {
        printf("\nFor Element-%d\n", i + 1);
        printf("Enter Profit: ");
        scanf("%d", &profits[i]);
        printf("Enter Weight: ");
        scanf("%d", &weights[i]);
    }

    int maxProfit = KnapSack(profits, weights, size, capacity);
    printf("\nMaximum Profit is: %d\n", maxProfit);

    return 0;
}