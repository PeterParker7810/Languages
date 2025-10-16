#include<stdio.h>

void ShellSort(int arr[], int size){
    int gap = size/2;

    while (gap > 0){
        for (int i = gap; i < size; i++){
            int curr = arr[i];
            int prev = i - gap;

            while (prev >= 0 && arr[prev] > curr){
                arr[prev + gap] = arr[prev];
                prev -= gap;
            }
            arr[prev + gap] = curr;
        }
        gap /= 2;
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

    ShellSort(arr, size);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++)printf("%d ", arr[i]);
    
    return 0;
}