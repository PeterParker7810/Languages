#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right, *parent;
} Node;

typedef struct { 
    Node* root;
} Heap;

typedef struct {
    Node** data;
    int front, rear, size;
} Queue;

Queue* createQueue(int cap) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Node**)malloc(sizeof(Node*) * cap);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, Node* node) {
    queue->data[queue->rear++] = node;
    queue->size++;
}

Node* dequeue(Queue* queue) {
    queue->size--;
    return queue->data[queue->front++];
}

int isEmpty(Queue* queue) {return queue->size == 0;}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = node->parent = NULL;
    return node;
}

Node** getLevelOrder(Node* root, int* count) {
    *count = 0;
    if (!root) return NULL;

    Node** nodes = (Node**)malloc(sizeof(Node*) * 1000);
    Queue* queue = createQueue(1000);

    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        nodes[(*count)++] = current;

        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
    }
    freeQueue(queue);
    return nodes;
}

void percolateUp(Node* node) {
    while (node->parent && node->data < node->parent->data) {
        int temp = node->data;
        node->data = node->parent->data;
        node->parent->data = temp;
        node = node->parent;
    }
}

void heapify(Node* node) {
    if (!node) return;

    Node* smallest = node;
    if (node->left && node->left->data < smallest->data) smallest = node->left;
    if (node->right && node->right->data < smallest->data) smallest = node->right;

    if (smallest != node) {
        int temp = node->data;
        node->data = smallest->data;
        smallest->data = temp;
        heapify(smallest);
    }
}

Node* getLastNode(Node* root) {
    int count;
    Node** nodes = getLevelOrder(root, &count);
    Node* last = count > 0 ? nodes[count - 1] : NULL;
    free(nodes);
    return last;
}

void insertNode(Heap* heap, int val) {
    Node* newNode = createNode(val);
    if (!heap->root) {
        heap->root = newNode;
        return;
    }

    int count;
    Node** nodes = getLevelOrder(heap->root, &count);

    for (int i = 0; i < count; i++) {
        Node* node = nodes[i];
        if (!node->left) {
            node->left = newNode;
            newNode->parent = node;
            percolateUp(newNode);
            break;
        } else if (!node->right) {
            node->right = newNode;
            newNode->parent = node;
            percolateUp(newNode);
            break;
        }
    }
    free(nodes);
}

void insert(Heap* heap, int val) {insertNode(heap, val);}

void deleteMin(Heap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return;
    }

    Node* last = getLastNode(heap->root);
    if (last == heap->root) {
        free(heap->root);
        heap->root = NULL;
        return;
    }

    heap->root->data = last->data;
    if (last->parent->left == last) last->parent->left = NULL;
    else last->parent->right = NULL;

    free(last);
    heapify(heap->root);
}

int findMin(Heap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return -1;
    } return heap->root->data;
}

int findMax(Heap* heap) {
    int count;
    Node** nodes = getLevelOrder(heap->root, &count);
    if (count == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int maxVal = nodes[0]->data;
    for (int i = 1; i < count; i++) if (nodes[i]->data > maxVal) maxVal = nodes[i]->data;
    free(nodes);
    return maxVal;
}

void display(Heap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return;
    }
    int count;
    Node** nodes = getLevelOrder(heap->root, &count);
    for (int i = 0; i < count; i++) printf("%d ", nodes[i]->data);
    printf("\n");
    free(nodes);
}

int main() {
    Heap heap;
    heap.root = NULL;

    printf("\nMin Heap Functions:\n1. Insert\n2. Delete Min\n3. Find Min\n4. Find Max\n5. Display\n");
    while (1) {
        int choice, elem;
        printf("\nEnter Heap Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            insert(&heap, elem);
        }
        else if (choice == 2) deleteMin(&heap);
        else if (choice == 3) printf("Min: %d\n", findMin(&heap));
        else if (choice == 4) printf("Max: %d\n", findMax(&heap));
        else if (choice == 5) display(&heap);
        else printf("Invalid choice\n");
    }
    return 0;
}