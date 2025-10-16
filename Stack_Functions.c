#include<stdio.h>
#include<stdlib.h>

void Push(int* stack, int* check, int size, int elem){
    if (*check > 0){
        stack[size-(--(*check))] = elem;
        printf("\nPushing %d to Stack\n", elem);
    } else printf("\nStack Overflow\n");
}

void Pop(int* stack, int* check, int size){
    if (*check == 0) printf("\nStack Underflow\n");
    else printf("\nPopped out %d\n", stack[size-((*check)++)-1]);
}

void Peek(int* stack, int size, int check, int peek){
    if (peek >= 0 && peek < size-check) printf("\nElement at Index %d is %d\n", peek, stack[size-peek-1]);
    else printf("\nIndex out of range\n");
}

void Display(int* stack, int size, int check){
    printf("\nDisplaying Stack Elements:\n");
    for (int i = 0; i < size-check; i++) printf("%d ", stack[i]);
    printf("\n");
}

int main(){
    int size, choice, elem, peek;
    printf("Enter the size of Stack: ");
    scanf("%d", &size);

    int check = size;
    int* stack = (int*)malloc(size * sizeof(int));
    printf("Stack Functions:\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Peek\n6. Count\n7. Display\n");

    while (1){
        printf("\nEnter Stack Function: ");
        scanf("%d", &choice);

        if (choice == 1){
            printf("Enter Element to be Pushed: ");
            scanf("%d", &elem);
            Push(stack, &check, size, elem);
        } 
        else if (choice == 2) Pop(stack, &check, size);
        else if (choice == 3){
            if (check == size) printf("\nStack is Empty\n");
            else printf("\nStack is not Empty\n");
        }
        else if (choice == 4){
            if (check == 0) printf("\nStack is Full\n");
            else printf("\nStack is not Full\n");
        }
        else if (choice == 5){
            printf("Enter Index to Peek: ");
            scanf("%d",&peek);
            Peek(stack, size, check, peek);
        } else if (choice == 6) printf("\nNumber of Elements in Stack are %d\n", size-check);
        else if (choice == 7) Display(stack, size, check);
        else printf("\nInvalid Choice\n");
    }

    return 0;
}