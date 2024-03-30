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

int binary_search(int *arr, int start, int end, int target)
{
    int     mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    
    return (-1);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int     len;
    int     x;

    len = sizeof(arr) / sizeof(arr[0]);
    x = 6;
    bubble_sort(arr, len);
    int result = binary_search(arr, 0, len-1, x);
    if (result != -1)
        printf("element is at %d position\n", result);
    else
        printf("element doesn't exist");
    return (0);
}