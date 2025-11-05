#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int FrogJump(int arr[], int size, int dp[]) {
    if (size == 0) return 0;
    if (size == 1) return abs(arr[1] - arr[0]); // base case for 2 stones

    if (dp[size] != -1) return dp[size];

    int left = FrogJump(arr, size - 1, dp) + abs(arr[size] - arr[size - 1]);
    int right = FrogJump(arr, size - 2, dp) + abs(arr[size] - arr[size - 2]);

    return dp[size] = (left < right) ? left : right;
}


int main(){
    int size, counter = 0;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    int arr[size], dp[size]; 
    for (int i = 0; i < size; i++) dp[i] = -1;
    for (int i = 0; i < size; i++) {
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nThe Elements in the array are:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    int result = FrogJump(arr, size - 1, dp);
    printf("\n\nMinimum Energy Required: %d", result);

    return 0;
}