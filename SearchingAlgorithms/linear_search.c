#include <stdio.h>

int linear_search(int *arr, int len, int x)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == x)
            return (i);
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
    int result = linear_search(arr, len, x);
    if (result != -1)
        printf("element is at %d position\n", result);
    else
        printf("element doesn't exist");
    return (0);
}