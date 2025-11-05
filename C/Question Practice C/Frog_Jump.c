#include<stdio.h>
#include<stdlib.h>

void FrogJump(int arr[], int solutions[], int size, int index, int energy, int* counter) {
    if (index >= size-1) {
        solutions[(*counter)++] = energy;
        return;
    }

    // Jump to the next stone
    if (index + 1 < size) FrogJump(arr, solutions, size, index + 1, energy + abs(arr[index] - arr[index + 1]), counter);

    // Jump to the stone after next
    if (index + 2 < size) FrogJump(arr, solutions, size, index + 2, energy + abs(arr[index] - arr[index + 2]), counter);
}

int main(){
    int size, counter = 0;
    printf("Enter the no of Elements: ");
    scanf("%d", &size);

    int arr[size], solutions[size*size]; // Maximum possible solutions

    for (int i = 0; i < size; i++) {
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nThe Elements in the array are:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    FrogJump(arr, solutions, size, 0, 0, &counter);
    int minEnergy = solutions[0];
    for (int i = 1; i < counter; i++) if (solutions[i] < minEnergy) minEnergy = solutions[i];
    printf("\n\nMinimum Energy Required: %d", minEnergy);

    return 0;
}