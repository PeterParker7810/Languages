#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int start, int mid, int end){
    int sizeL = mid-start+1;
    int sizeR = end-mid;

    int *Left = (int*)malloc(sizeL * sizeof(int));
    int *Right = (int*)malloc(sizeR * sizeof(int));
    for (int i = 0; i < sizeL; i++) Left[i] = arr[start+i];
    for (int i = 0; i < sizeR; i++) Right[i] = arr[mid+1+i];

    int i = 0, j = 0, k = start;
    while (i < sizeL && j <sizeR){
        if (Left[i] <= Right[j]) arr[k++] = Left[i++];
        else arr[k++] = Right[j++];
    }

    while (i < sizeL) arr[k++] = Left[i++];
    while (j < sizeR) arr[k++] = Right[j++];

    free(Left);
    free(Right);
}

void MergeSort(int arr[], int start, int end){
    if (start < end){
        int mid = start + (end-start)/2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, start, mid, end);
    }
}

int main(){
    int size;
    printf("Enter the no of Elements: ");
    scanf("%d",&size);

    int arr[size];
    for (int i = 0; i < size; i++){
        printf("Enter the Element: ");
        scanf("%d",&arr[i]);
    }

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ",arr[i]);

    MergeSort(arr, 0, size-1);
    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}