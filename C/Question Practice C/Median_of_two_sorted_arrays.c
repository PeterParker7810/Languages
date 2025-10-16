#include<stdio.h>

int main(){
    int limit1,limit2,limit3,arr1[100],arr2[100],arr3[100];

    //Inputting Elements for Array-1
    printf("Enter no of elements for Array-1: ");
    scanf("%d",&limit1);    

    printf("For Array-1:\n");
    for (int i = 0; i < limit1; i++){
        printf("Enter the element: ");
        scanf("%d",&arr1[i]);
    }

    //Inputting Elements for Array-2
    printf("\nEnter no of elements for Array-2: ");
    scanf("%d",&limit2);    

    printf("For Array-2:\n");
    for (int i = 0; i < limit2; i++){
        printf("Enter the element: ");
        scanf("%d",&arr2[i]);
    }

    //Merging and Sorting Arrays
    limit3 = limit1 + limit2;

    printf("\nElements for Array-1:\n");
    for (int i = 0; i < limit1; i++){
        printf("%d ",arr1[i]);
        arr3[i] = arr1[i];
    }
    
    printf("\nElements for Array-2:\n");
    for (int i = 0; i < limit2; i++){
        printf("%d ",arr2[i]);
        arr3[i+limit1] = arr2[i];
    }

    int range = limit3;     //Bubble Sort
    while (range > 0){
        for (int i = 0; i <= range; i++){
            for (int j = i+1; j < range; j++){
                if (arr3[i] > arr3[j]){
                    arr3[i] += arr3[j];
                    arr3[j] = arr3[i] - arr3[j];
                    arr3[i] -= arr3[j];
                }
            }
        }
        range--;
    }

    printf("\nElements for Merged Array:\n");
    for (int i = 0; i < limit3; i++){
        printf("%d ",arr3[i]);
    }

    printf("\nMedian of Sorted Arrays: ");
    if ((limit3-1)%2 == 0){
        printf("%d",arr3[(limit3-1)/2]);
    }
    else{
        float avg = ((float)arr3[limit3/2] + (float)arr3[(limit3-1)/2])/2;
        printf("%.2f",avg);
    }

    return 0;
}