#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkedList {
    int size;
    int count;
    struct Node* head;
};

void Initialize(struct LinkedList* list, int size) {
    list->head = NULL;
    list->count = 0;
    list->size = size;
}

void Enqueue(struct LinkedList* list, int val){
    if (list->count == list->size) printf("Queue is Full\n");
    else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (list->head == NULL) list->head = newNode;
        else {
            struct Node* temp = list->head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }

        list->count++;
        printf("Enqueued %d\n", val);
    }
}

void Dequeue(struct LinkedList* list){
    if (list->head == NULL) printf("Queue is Empty\n");
    else {
        struct Node* temp = list->head;
        printf("Dequeued %d\n", temp->data);
        list->head = list->head->next;
        free(temp);
        list->count--;
    }
}

void isFull(struct LinkedList* list){
    if (list->count == list->size) printf("Queue is Full\n");
    else printf("Queue is Not Full\n");
}

void isEmpty(struct LinkedList* list){
    if (list->head == NULL) printf("Queue is Empty\n");
    else printf("Queue is Not Empty\n");
}

void Count(struct LinkedList* list) {printf("Number of Elements in Queue are %d\n", list->count);}

void Display(struct LinkedList* list){
    if (list->head == NULL) printf("Queue is Empty\n");
    else {
        struct Node* temp = list->head;
        printf("Displaying Queue Elements:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    struct LinkedList queue;
    Initialize(&queue, size);

    printf("Queue Functions:\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Count\n6. Display\n");
    while (1){
        int choice, elem, peek;
        printf("\nEnter Queue Function: ");
        scanf("%d", &choice);

        if (choice == 1){
            printf("Enter Element to Enqueue: ");
            scanf("%d", &elem);
            Enqueue(&queue, elem);
        }
        else if (choice == 2) Dequeue(&queue);
        else if (choice == 3) isEmpty(&queue);
        else if (choice == 4) isFull(&queue);
        else if (choice == 5) Count(&queue);
        else if (choice == 6) Display(&queue);
        else printf("Invalid Choice\n");
    }
    
    return 0;
}