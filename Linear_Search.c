#include<stdio.h>

int LinearSearch(int arr[], int size, int find){
    for (int i = 0; i < size; i++)if (arr[i] == find) return i;
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

    int found = LinearSearch(arr, size, find);

    if (found == -1) printf("Element Not Found\n");
    else printf("Element Found at Index %d\n", found);    
    
    return 0;
}