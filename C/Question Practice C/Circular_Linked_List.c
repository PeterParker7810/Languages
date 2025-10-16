#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {struct Node* head;};

void Initialize(struct LinkedList* list) {list->head = NULL;}

void InsertAtBeginning(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) temp = temp->next;

        newNode->next = list->head;
        temp->next = newNode;
        list->head = newNode;
    }

    printf("Inserted head node with value %d\n", newNode->data);
}

void InsertAtEnd(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        printf("Inserted head node with value %d\n", newNode->data);
        return;
    }

    struct Node* temp = list->head;
    while (temp->next != list->head) temp = temp->next;

    temp->next = newNode;
    newNode->next = list->head;

    printf("Inserted new node with value %d\n", newNode->data);
}

void DeleteAtBeginning(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;

    if (temp->next == list->head) {
        printf("Deleted head node with value %d\n", temp->data);
        free(temp);
        list->head = NULL;
        return;
    }

    struct Node* last = list->head;
    while (last->next != list->head) last = last->next;

    list->head = list->head->next;
    last->next = list->head;

    printf("Deleted head node with value %d\n", temp->data);
    free(temp);
}

void DeleteAtEnd(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;

    if (temp->next == list->head) {
        printf("Deleted head node with value %d\n", temp->data);
        free(temp);
        list->head = NULL;
        return;
    }

    struct Node* prev = NULL;
    do{
        prev = temp;
        temp = temp->next;
    } while (temp->next != list->head);

    prev->next = list->head;
    printf("Deleted node with value %d\n", temp->data);
    free(temp);
}

void Display(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(head)\n");
}

int main() {
    struct LinkedList l1;
    Initialize(&l1);

    printf("Circular Singly Linked List Operations:\n");
    printf("1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Display\n");

    while (1) {
        int choice, elem;
        printf("\nEnter Linked List Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the Value to insert: ");
            scanf("%d", &elem);
            InsertAtBeginning(&l1, elem);
        } else if (choice == 2) {
            printf("Enter the Value to insert: ");
            scanf("%d", &elem);
            InsertAtEnd(&l1, elem);
        } 
        else if (choice == 3) DeleteAtBeginning(&l1);
        else if (choice == 4) DeleteAtEnd(&l1);
        else if (choice == 5) Display(&l1);
        else printf("Enter Valid Operation\n");
    }

    return 0;
}