#include <stdio.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *arr, int len)
{
    int     i;
    int     j;
    int     x;

    i = 1;
    j = 0;
    //min_val = 0;
    while (i != len)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
        i++;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}