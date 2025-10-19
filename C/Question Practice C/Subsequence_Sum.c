#include<stdio.h>

void SubSequence(int index, int arr[], int ds[], int size, int check, int* found){
    if (index == size) {
        int sum = 0;
        for (int i = 0; i < size; i++) if (ds[i]) sum += arr[i];
        if (sum == check) {
            printf("The Numbers ");
            for (int i = 0; i < size; i++) if (ds[i]) printf("%d ", arr[i]);
            printf("add upto %d\n", check);
            (*found) = 1;
            return;
        }else return;
    }

    // Include the current element
    ds[index] = 1;
    SubSequence(index + 1, arr, ds, size, check, found);

    // Exclude the current element
    ds[index] = 0;
    SubSequence(index + 1, arr, ds, size, check, found);
}

int main(){
    int size, check, found = 0;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    int arr[size], ds[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    printf("\n\nEnter the number to check: ");
    scanf("%d", &check);
    SubSequence(0, arr, ds, size, check, &found);
    if (!found) printf("No Pairs Found...");
    
    return 0;
}