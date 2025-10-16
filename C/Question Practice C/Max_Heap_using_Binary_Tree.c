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

int isEmpty(Queue* queue) { return queue->size == 0; }

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
        Node* curr = dequeue(queue);
        nodes[(*count)++] = curr;

        if (curr->left) enqueue(queue, curr->left);
        if (curr->right) enqueue(queue, curr->right);
    }
    freeQueue(queue);
    return nodes;
}

void percolateUp(Node* node) {
    while (node->parent && node->data > node->parent->data) {
        int temp = node->data;
        node->data = node->parent->data;
        node->parent->data = temp;
        node = node->parent;
    }
}

void heapify(Node* node) {
    if (!node) return;

    Node* largest = node;
    if (node->left && node->left->data > largest->data) largest = node->left;
    if (node->right && node->right->data > largest->data) largest = node->right;

    if (largest != node) {
        int temp = node->data;
        node->data = largest->data;
        largest->data = temp;
        heapify(largest);
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
    } free(nodes);
}

void insert(Heap* heap, int val) {insertNode(heap, val);}

void deleteMax(Heap* heap) {
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

int findMaxRoot(Heap* heap) {
    if (!heap->root) {
        printf("Heap is empty\n");
        return -1;
    } return heap->root->data;
}

int findMin(Heap* heap) {
    int count;
    Node** nodes = getLevelOrder(heap->root, &count);
    if (count == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int minVal = nodes[0]->data;
    for (int i = 1; i < count; i++) if (nodes[i]->data < minVal) minVal = nodes[i]->data;
    free(nodes);
    return minVal;
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

    printf("\nMax Heap Functions:\n1. Insert\n2. Delete Max\n3. Find Max\n4. Find Min\n5. Display\n");
    while (1) {
        int choice, elem;
        printf("\nEnter Heap Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            insert(&heap, elem);
        }
        else if (choice == 2) deleteMax(&heap);
        else if (choice == 3) printf("Max: %d\n", findMaxRoot(&heap));
        else if (choice == 4) printf("Min: %d\n", findMin(&heap));
        else if (choice == 5) display(&heap);
        else printf("Invalid choice\n");
    }
    return 0;
}