#include <stdio.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int len)
{
    int     i;
    int     j;
    int     min_val;

    i = 0;
    j = 0;
    min_val = 0;
    while (i != len)
    {
        j = i+1;
        min_val = i;
        while (j != len)
        {
            if (arr[j] < arr[min_val])
                min_val = j;
            j++;
        }
        swap(&arr[min_val], &arr[i]);
        i++;
        min_val = i;
    }
}

int main()
{
    int arr[] = {-2147483647, 1, 2147483647, 2, 3};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}