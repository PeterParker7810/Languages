#include<stdio.h>

void SubSequence(int index, int arr[], int ds[], int size){
    if (index == size) {
        for (int i = 0; i < size; i++) if (ds[i]) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // Include the current element
    ds[index] = 1;
    SubSequence(index + 1, arr, ds, size);

    // Exclude the current element
    ds[index] = 0;
    SubSequence(index + 1, arr, ds, size);
}

int main(){
    int size;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    int arr[size], ds[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    printf("\n\nAll Subsequences:\n");
    printf("{ }\n");
    SubSequence(0, arr, ds, size);

    
    return 0;
}