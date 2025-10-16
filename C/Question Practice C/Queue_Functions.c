#include<stdio.h>
#include<stdlib.h>

void Reverse(int* arr, int size){
    for (int i = 0; i < size / 2; i++){
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void Enqueue(int* queue, int* check, int size, int elem){
    int count = size - *check;
    if (*check == 0) printf("Queue is Full\n");
    else {
        Reverse(queue, count);
        queue[count] = elem;
        Reverse(queue, count + 1);
        (*check)--;
        printf("Enqueued %d\n", elem);
    }
}

void Dequeue(int* queue, int* check, int size){
    int count = size - *check;
    if (*check == size) printf("Queue is Empty\n");
    else {
        Reverse(queue, count);
        printf("Dequeued %d\n", queue[count - 1]);
        Reverse(queue, count - 1);
        (*check)++;
    }
}

void Display(int* queue, int size, int check){
    int count = size - check;
    printf("Displaying Queue Elements:\n");
    for (int i = 0; i < count; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    int check = size;
    int* queue = (int*)malloc(size * sizeof(int));

    printf("Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display");

    while (1){
        int choice, elem;
        printf("\nEnter Queue Function: ");
        scanf("%d", &choice);

        if (choice == 1){
            printf("Enter Element to Enqueue: ");
            scanf("%d", &elem);
            Enqueue(queue, &check, size, elem);
        } 
        else if (choice == 2) Dequeue(queue, &check, size);
        else if (choice == 3) printf(check == 0 ? "Queue is Full\n" : "Queue is not Full\n");
        else if (choice == 4) printf(check == size ? "Queue is Empty\n" : "Queue is not Empty\n");
        else if (choice == 5) printf("Number of Elements in Queue are %d\n", size - check);
        else if (choice == 6) Display(queue, size, check);
        else printf("Invalid Choice\n");
    }

    return 0;
}