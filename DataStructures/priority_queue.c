#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap() {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    maxHeap->size = 0;
    maxHeap->capacity = MAX_SIZE;
    return maxHeap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void insert(MaxHeap* maxHeap, int value) {
    if (maxHeap->size == maxHeap->capacity) {
        printf("Heap is full. Cannot insert %d\n", value);
        return;
    }

    maxHeap->size++;
    int i = maxHeap->size - 1;
    maxHeap->arr[i] = value;

    while (i != 0 && maxHeap->arr[parent(i)] < maxHeap->arr[i]) {
        swap(&maxHeap->arr[i], &maxHeap->arr[parent(i)]);
        i = parent(i);
    }
    printf("Inserted %d\n", value);
}

int extractMax(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap is empty. Cannot extract maximum\n");
        return -1;
    }
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->arr[0];
    }

    int root = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
    maxHeap->size--;

    int i = 0;
    while (1) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < maxHeap->size && maxHeap->arr[left] > maxHeap->arr[largest])
            largest = left;
        if (right < maxHeap->size && maxHeap->arr[right] > maxHeap->arr[largest])
            largest = right;

        if (largest != i) {
            swap(&maxHeap->arr[i], &maxHeap->arr[largest]);
            i = largest;
        } else {
            break;
        }
    }

    return root;
}

int peek(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap is empty. Cannot peek\n");
        return -1;
    }
    return maxHeap->arr[0];
}

void increaseKey(MaxHeap* maxHeap, int index, int newValue) {
    if (index >= maxHeap->size) {
        printf("Invalid index. Cannot increase key\n");
        return;
    }
    if (newValue < maxHeap->arr[index]) {
        printf("New value is smaller than the current value. Cannot increase key\n");
        return;
    }
    maxHeap->arr[index] = newValue;
    while (index != 0 && maxHeap->arr[parent(index)] < maxHeap->arr[index]) {
        swap(&maxHeap->arr[index], &maxHeap->arr[parent(index)]);
        index = parent(index);
    }
    printf("Key at index %d increased to %d\n", index, newValue);
}

void destroyMaxHeap(MaxHeap* maxHeap) {
    free(maxHeap->arr);
    free(maxHeap);
}

int main() {
    MaxHeap* maxHeap = createMaxHeap();

    insert(maxHeap, 5);
    insert(maxHeap, 3);
    insert(maxHeap, 8);
    insert(maxHeap, 9);
    insert(maxHeap, 1);

    printf("Maximum element: %d\n", peek(maxHeap));

    increaseKey(maxHeap, 2, 10);

    printf("Extracted maximum element: %d\n", extractMax(maxHeap));

    destroyMaxHeap(maxHeap);

    return 0;
}
