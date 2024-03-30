#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int arr_size) {
    int current_size;
    int left_start;

    for (current_size = 1; current_size <= arr_size - 1; current_size = 2 * current_size) {
        for (left_start = 0; left_start < arr_size - 1; left_start += 2 * current_size) {
            int mid = left_start + current_size - 1;

            int right_end = (left_start + 2 * current_size - 1) < (arr_size - 1) ? (left_start + 2 * current_size - 1) : (arr_size - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}


int main()
{
    int arr[] = {132, 45, 2, 3, -1, 0, 9};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}