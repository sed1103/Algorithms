#include <stdio.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void shaker_sort(int *arr, int len)
{
    int     i; 
    int     is_swapped;

    i = 0;
    is_swapped = 1;
    while (is_swapped)
    {
        is_swapped = 0;
        while (i <= len - 1)
        {
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
                is_swapped = 1;
            }
            i++;
        }
        if (!is_swapped)
            break;
        is_swapped = 0;
        i = len - 1;
        while (i != 0)
        {
            if (arr[i] < arr[i-1])
            {
                swap(&arr[i], &arr[i-1]);
                is_swapped = 1;
            }
            i--;
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    shaker_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}