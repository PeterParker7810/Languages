#include<stdio.h>
#include<stdlib.h>

void CountingSort(int arr[], int size){
    int max = arr[0], min = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    } 

    int* count = (int*)malloc((max-min+1) * sizeof(int));
    for (int i = 0; i < max-min+1; i++) count[i] = 0;

    for (int i = 0; i < size; i++) count[arr[i]-min]++;
    int index = 0;

    for (int i = 0; i < (max-min+1); i++) for (int j = 0; j < count[i]; j++) arr[index++] = i+min;
    free(count);
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

    CountingSort(arr, size);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}