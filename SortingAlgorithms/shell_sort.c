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

void shell_sort(int *arr, int len)
{
    int     gap;

    gap = len / 2;
    while (gap > 1)
    {
        for (int i = 0; i <= gap; i++)
        {
            if (arr[i] > arr[i+gap])
            {
                swap(&arr[i], &arr[i+gap]);
            }
        }
        gap = gap / 2;
    }
    insertion_sort(arr, len);
}

int main()
{
    int arr[] = {3, 22, 14, -1, 31, 10, 7, 25};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    shell_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}