#include <stdio.h>

int partition(int *arr, int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h;
    int temp;

    while (i < j) {
        do {
            i++;
        } while (arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int *arr, int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}

int main() {
    int arr[7] = {11, 4, 7, 2, 10, 2, 20};
    int length = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, length - 1);
    for (int loop = 0; loop < length; loop++)
        printf("%d ", arr[loop]);
    return 0;
}
