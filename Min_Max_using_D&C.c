#include <stdio.h>

void findMinMax(int arr[], int start, int end, int* min, int* max) {
    if (start == end) {
        if (arr[start] < *min) *min = arr[start];
        if (arr[start] > *max) *max = arr[start];
        return;
    }

    if (end == start + 1) {
        if (arr[start] < arr[end]) {
            if (arr[start] < *min) *min = arr[start];
            if (arr[end] > *max) *max = arr[end];
        } else {
            if (arr[end] < *min) *min = arr[end];
            if (arr[start] > *max) *max = arr[start];
        } return;
    }

    int mid = (start + end)/2;
    findMinMax(arr, start, mid, min, max);
    findMinMax(arr, mid + 1, end, min, max);
}

int main() {
    int size, min, max;
    printf("Enter the number of Elements: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    min, max = arr[0];
    findMinMax(arr, 0, size - 1, &min, &max);

    printf("\nMinimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);

    return 0;
}