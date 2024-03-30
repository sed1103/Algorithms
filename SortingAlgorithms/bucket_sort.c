#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
        return (NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** bucket, int value) {
    Node* newNode = createNode(value);
    if (*bucket == NULL) {
        *bucket = newNode;
    } else {
        Node* temp = *bucket;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertionSort(Node** bucket) {
    if (*bucket == NULL || (*bucket)->next == NULL) {
        return;
    }
    Node *sortedList = NULL;
    Node *current = *bucket;
    while (current != NULL) {
        Node *next = current->next;
        if (sortedList == NULL || current->data < sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            Node *temp = sortedList;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *bucket = sortedList;
}

void bucket_sort(int *arr, int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int numBuckets = max / 10 + 1;

    Node** buckets = (Node**)malloc(numBuckets * sizeof(Node*));
    if (!buckets)
        return;

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }
    for (int i = 0; i < len; i++) {
        int index = arr[i] / 10;
        insertNode(&buckets[index], arr[i]);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(&buckets[i]);
        Node* temp = buckets[i];
        while (temp != NULL) {
            arr[index++] = temp->data;
            temp = temp->next;
        }
    }
}


int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}