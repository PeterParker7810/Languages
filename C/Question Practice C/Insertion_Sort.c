#include<stdio.h>

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    int size;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++){
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    InsertionSort(arr, size);
    printf("\n\nAfter Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}