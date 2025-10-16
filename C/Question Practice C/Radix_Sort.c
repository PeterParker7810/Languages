#include<stdio.h>
#include<stdlib.h>

void CountingSort(int arr[], int size, int last){
    int* count = (int*)malloc(10*sizeof(int));
    int* output = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < 10; i++) count[i] = 0;

    for (int i = 0; i < size; i++){
        int digit = (arr[i]/last) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i-1];

    for (int i = size - 1; i >= 0; i--){
        int digit = (arr[i]/last) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < size; i++) arr[i] = output[i];

    free(count);
    free(output);
}

void RadixSort(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] > max) max = arr[i];
    for (int last = 1; max/last > 0; last *= 10) CountingSort(arr, size, last);
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

    RadixSort(arr, size);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}