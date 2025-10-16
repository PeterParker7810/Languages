#include<stdio.h>

void Push(int* st, int* top, int size){
    if ((*top) == size-1){
        printf("Stack Overflow\n");
    }
    else{
        int val;
        printf("Enter value to push: ");
        scanf("%d", &val);
        (*top)++;
        st[(*top)] = val;
        printf("Pushed %d\n", val);
    }
}

void Pop(int* st, int* top, int size){
    if ((*top) == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Popped out %d\n", st[(*top)]);
        (*top)--;
    }
}

void Display(int* st, int top){
    printf("Displaying Stack Elements:\n");
    for (int i = 0; i <= top; i++){
        printf("%d ", st[i]);
    }
    printf("\n");
}

int main(){
    int top = -1;
    int size; 

    printf("Enter size of Stack: ");
    scanf("%d", &size);

    int stack[size];

    int choice;
    while (1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            Push(stack, &top, size);
        }
        else if (choice == 2){
            Pop(stack, &top, size);
        }
        else if (choice == 3){
            Display(stack, top);
        }
        else if (choice == 4){
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    
    return 0;
}