#include <stdio.h>

void removeDuplicates(int arr[], int *n) {
    int i, j, k;

    // Outer loop to pick each element one by one
    for (i = 0; i < *n; i++) {
        // Inner loop to check for duplicates
        for (j = i + 1; j < *n; ) {
            if (arr[i] == arr[j]) {
                // If duplicate is found, shift elements left
                for (k = j; k < *n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*n)--;  // Reduce size of the array
            } else {
                j++;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 3, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates:\n");
    printArray(arr, n);

    return 0;
}

