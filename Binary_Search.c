#include<stdio.h>

int BinarySearch(int arr[], int size, int find){
    int start = 0, end = size-1;
    while (start <= end){
        int mid = start + (end-start)/2;

        if (arr[mid] == find) return mid;
        else if (arr[mid] < find) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

int main(){
    int size, find;
    printf("Enter the Number of Elements: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++){
        printf("Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the Element to Find: ");
    scanf("%d", &find);

    int found = BinarySearch(arr, size, find);
    if (found == -1) printf("Element Not Found\n");
    else printf("Element Found at Index %d\n", found);    
    
    return 0;
}