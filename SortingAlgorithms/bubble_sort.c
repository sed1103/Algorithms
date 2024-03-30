#include <stdio.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int len)
{
    int     i;
    int     j;

    i = 0;
    while (i != len - 1)
    {
        j = 0;
        while (j != len - 1)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
            j++;
        }
        i++;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}