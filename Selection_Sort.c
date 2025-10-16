#include<stdio.h>

void SelectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        int min = i;
        for (int j = i+1; j < size; j++) if (arr[j] < arr[min]) min = j;
        
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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
    
    SelectionSort(arr, size);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    return 0;
}