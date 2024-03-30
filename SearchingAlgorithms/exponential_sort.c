#include <stdio.h>

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

int get_min(int a, int b)
{
    if (a < b)
    {
        return (a);
    }
    else
    {
        return (b);
    }
    
}
int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
 
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    return binary_search(arr, i/2, get_min(i, n-1), x);
}
int main()
{
    int arr[] = {-1, 0, 4, 12, 43, 100, 467};
    int     len;
    int     x;

    len = sizeof(arr) / sizeof(arr[0]);
    x = -1;
    //bubble_sort(arr, len);
    int result = binary_search(arr, 0, len-1, x);
    if (result != -1)
        printf("element is at %d position\n", result);
    else
        printf("element doesn't exist");
    return (0);
}