#include<stdio.h>

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        int swapped = 0;
        for (int j = 0; j < size-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
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

    BubbleSort(arr, size);
    printf("\n\nAfter Sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}