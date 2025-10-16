#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {struct Node* head;};
void Initialize(struct LinkedList* list) {list->head = NULL;}

void InsertAtBeginning(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = list->head;
    list->head = newNode;
    printf("Inserted head node with value %d\n", newNode->data);
}

void InsertAtEnd(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    struct Node* temp = list->head;
    if (temp == NULL) {
        list->head = newNode;
        printf("Inserted head node with value %d\n", newNode->data);
        return;
    }

    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    printf("Inserted new node with value %d\n", newNode->data);
}

void DeleteAtBeginning(struct LinkedList* list){
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;
    list->head = list->head->next;
    printf("Deleted node with value %d\n", temp->data);
    free(temp);
}

void Searching(struct LinkedList* list, int val){
    int found = 0, node = 0;
    struct Node* temp = list->head;

    while (temp != NULL){
        node++;
        if (temp->data == val){
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) printf("Value %d not found in the list\n", val);
    else printf("Value %d found at node %d\n", val, node);
}

void DeleteAtEnd(struct LinkedList* list){
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;
    if (temp->next == NULL) {
        printf("Deleted head node with value %d\n", temp->data);
        free(temp);
        list->head = NULL;
        return;
    }

    while (temp->next->next != NULL) temp = temp->next;
    struct Node* toDelete = temp->next;
    printf("Deleted node with value %d\n", toDelete->data);
    temp->next = NULL;
    free(toDelete);
}

void Display(struct LinkedList* list){
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct LinkedList l1;
    Initialize(&l1);

    printf("Linked List Operations:\n1. InsertAtBeginning\n2. InsertAtEnd\n3. DeleteAtBeginning\n4. DeleteAtEnd\n5. Searching\n6. Display\n");
    while (1){
        int choice, elem;
        printf("\nEnter Linked List Operation: ");
        scanf("%d",&choice);

        if (choice == 1) {
            printf("Enter the Value to insert: ");
            scanf("%d",&elem);
            InsertAtBeginning(&l1, elem); 
        } else if (choice == 2) {
            printf("Enter the Value to insert: ");
            scanf("%d",&elem);
            InsertAtEnd(&l1, elem);
        } 
        else if (choice == 3) DeleteAtBeginning(&l1);
        else if (choice == 4) DeleteAtEnd(&l1);
        else if (choice == 5) {
            printf("Enter Value to be Searched: ");
            scanf("%d", &elem);
            Searching(&l1, elem);
        } else if (choice == 6) Display(&l1);
        else printf("Enter Valid Operation\n");
    }
    
    return 0;
}