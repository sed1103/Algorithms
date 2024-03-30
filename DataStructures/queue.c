#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} CircularQueue;

CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = MAX_SIZE;
    return queue;
}

int isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}

int isFull(CircularQueue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->arr[queue->rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    printf("Dequeued %d\n", item);
    return item;
}

void destroyCircularQueue(CircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int main() {
    CircularQueue* queue = createCircularQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    destroyCircularQueue(queue);

    return 0;
}
