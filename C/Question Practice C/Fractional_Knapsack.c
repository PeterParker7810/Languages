#include<stdio.h>

float KnapSack(int size, float profits[], float weights[], float pw[], int capacity) {
    float result = 0;

    while (capacity > 0) {
        int index = -1;
        for (int i = 0; i < size; i++) if (pw[i] != -1 && (index == -1 || pw[i] > pw[index])) index = i;

        if (index == -1) break;
        if (weights[index] <= capacity) {
            result += profits[index];
            capacity -= weights[index];
            pw[index] = -1;
        } else {
            result += pw[index] * capacity;
            capacity = 0;
        }
    }
    return result;
}

int main(){
    int size, capacity;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    printf("Enter the capacity of Knapsack: ");
    scanf("%d", &capacity);

    float profits[size], weights[size], pw[size];
    for (int i = 0; i < size; i++) {
        printf("\nFor Element-%d\n", i + 1);
        printf("Enter Profit: ");
        scanf("%f", &profits[i]);
        printf("Enter Weight: ");
        scanf("%f", &weights[i]);
        pw[i] = profits[i] / weights[i];
    }

    float maxProfit = KnapSack(size, profits, weights, pw, capacity);
    printf("\nMaximum Profit is: %.2f\n", maxProfit);

    return 0;
}