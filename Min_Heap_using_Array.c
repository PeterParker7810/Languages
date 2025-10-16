#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size, capacity;
} Heap;

Heap* createHeap(int cap) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = cap;
    heap->arr = (int*)malloc(sizeof(int) * cap);
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(Heap* heap, int i) {
    int min = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[min]) min = left;
    if (right < heap->size && heap->arr[right] < heap->arr[min]) min = right;

    if (min != i) {
        swap(&heap->arr[i], &heap->arr[min]);
        heapify(heap, min);
    }
}

void insert(Heap* heap, int val) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }
    heap->arr[heap->size] = val;
    int i = heap->size++;
    while (i != 0 && heap->arr[(i-1)/2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteMin(Heap* heap) {
    if (heap->size <= 0) printf("Heap is empty\n");
    else if (heap->size == 1) heap->size--;
    else {
        heap->arr[0] = heap->arr[(heap->size--) - 1];
        heapify(heap, 0);
    }
}

int findMin(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    } return heap->arr[0];
}

int findMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int max = heap->arr[heap->size/2];
    for (int i = heap->size/2 + 1; i < heap->size; i++) if (heap->arr[i] > max) max = heap->arr[i];
    return max;
}

void display(Heap* heap) {
    if (heap->size == 0) printf("Heap is empty\n");
    else {
        for (int i = 0; i < heap->size; i++) printf("%d ", heap->arr[i]);
        printf("\n");
    }
}

int main() {
    int cap;
    printf("Enter the size of Heap: ");
    scanf("%d", &cap);
    Heap* heap = createHeap(cap);

    printf("\nHeap Functions:\n1. Insert\n2. Delete Min\n3. Find Min\n4. Find Max\n5. Display\n");
    while (1) {
        int choice, elem;
        printf("\nEnter Heap Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            insert(heap, elem);
        } 
        else if (choice == 2) deleteMin(heap);
        else if (choice == 3) printf("Min: %d\n", findMin(heap));
        else if (choice == 4) printf("Max: %d\n", findMax(heap));
        else if (choice == 5) display(heap);
        else printf("Invalid choice\n");
    }

    return 0;
}