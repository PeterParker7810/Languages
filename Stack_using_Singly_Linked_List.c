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
};

void Push(struct LinkedList* list, int val){
    if (list->count == list->size) printf("Stack is Full\n");
    else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
        printf("Pushed %d to Stack\n", val);
    }
}


void Pop(struct LinkedList* list){
    if (list->head == NULL) printf("Stack is Empty\n");
    else {
        struct Node* temp = list->head;
        printf("Popped out %d\n", temp->data);
        list->head = list->head->next;
        free(temp);
        list->count--;
    }
}


void isFull(struct LinkedList* list){
    if (list->count == list->size) printf("Stack is Full\n");
    else printf("Stack is Not Full\n");
}

void isEmpty(struct LinkedList* list){
    if (list->head == NULL) printf("Stack is Empty\n");
    else printf("Stack is Not Empty\n");
}

void Peek(struct LinkedList* list, int index){
    if (index < 0 || index >= list->count) printf("Index out of range\n");
    else {
        struct Node* temp = list->head;
        for (int i = 0; i < index; i++) temp = temp->next;
        printf("Element at Index %d is %d\n", index, temp->data);
    }
}

void Count(struct LinkedList* list){
    printf("Number of Elements in Stack are %d\n", list->count);
}

void Display(struct LinkedList* list){
    if (list->head == NULL) printf("Stack is Empty\n");
    else {
        struct Node* temp = list->head;
        printf("Displaying Stack Elements:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of Stack: ");
    scanf("%d", &size);

    struct LinkedList stack;
    Initialize(&stack, size);

    printf("Stack Functions:\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Peek\n6. Count\n7. Display\n");
    while (1){
        int choice, elem, peek;
        printf("\nEnter Stack Function: ");
        scanf("%d", &choice);

        if (choice == 1){
            printf("Enter Element to be Pushed: ");
            scanf("%d", &elem);
            Push(&stack, elem);
        }
        else if (choice == 2) Pop(&stack);
        else if (choice == 3) isEmpty(&stack);
        else if (choice == 4) isFull(&stack);
        else if (choice == 5){
            printf("Enter Index to Peek: ");
            scanf("%d", &peek);
            Peek(&stack, peek);
        } 
        else if (choice == 6) Count(&stack);
        else if (choice == 7) Display(&stack);
        else printf("Invalid Choice\n");
    }
    
    return 0;
}