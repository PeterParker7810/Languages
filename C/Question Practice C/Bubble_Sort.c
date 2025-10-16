#include<stdio.h>

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int size;
    printf("Enter the Number of Elements: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++){
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    
    BubbleSort(arr, size);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    return 0;
}