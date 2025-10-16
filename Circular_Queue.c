#include <stdio.h>
#include <stdlib.h>

void Enqueue(int* queue, int* front, int* rear, int size, int* count, int elem) {
    if (*count == size) printf("Queue is Full\n");
    else {
        *rear = (*rear + 1) % size;
        queue[*rear] = elem;
        (*count)++;
        printf("Enqueued %d\n", elem);
    }    
}

void Dequeue(int* queue, int* front, int* rear, int size, int* count) {
    if (*count == 0) printf("Queue is Empty\n");
    else {
        *front = (*front + 1) % size;
        printf("Dequeued %d\n", queue[*front]);
        (*count)--;
    }
}

void Display(int* queue, int front, int count, int size) {
    printf("Displaying Queue Elements:\n");
    for (int i = 0; i < count; i++) {
        int index = (front + 1 + i) % size;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    int* queue = (int*)malloc(size * sizeof(int));
    int front = -1, rear = -1, count = 0;

    printf("Circular Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Count\n6. Display\n");
    while (1) {
        int choice, elem;
        printf("\nEnter Circular Queue Function: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Element to Enqueue: ");
            scanf("%d", &elem);
            Enqueue(queue, &front, &rear, size, &count, elem);
        }
        else if (choice == 2) Dequeue(queue, &front, &rear, size, &count);
        else if (choice == 3) printf(count == size ? "Queue is Full\n" : "Queue is not Full\n");
        else if (choice == 4) printf(count == 0 ? "Queue is Empty\n" : "Queue is not Empty\n");
        else if (choice == 5) printf("Number of Elements in Queue are %d\n", count);
        else if (choice == 6) Display(queue, front, count, size);
        else printf("Invalid Choice\n");
    }

    return 0;
}