#include<stdio.h>
#include<stdlib.h>

int Partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if (arr[j] <= pivot){
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

void QuickSort(int arr[], int start, int end){
    if (start < end){
        int part = Partition(arr, start, end);

        QuickSort(arr, start, part - 1);
        QuickSort(arr, part + 1, end);
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
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    QuickSort(arr, 0, size - 1);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}