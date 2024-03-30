#include <stdio.h>

int interpolation_search(int arr[], int l, int h, int x)
{
    int index;
    if (l <= h && x >= arr[l] && x <= arr[h]) {
        index = l + (((double)(h - l) / (arr[h] - arr[l])) * (x - arr[l]));
        if (arr[index] == x)
            return index;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int     len;
    int     x;

    len = sizeof(arr) / sizeof(arr[0]);
    x = 5;
    //bubble_sort(arr, len);
    int result = interpolation_search(arr, 0, len-1, x);
    if (result != -1)
        printf("element is at %d position\n", result);
    else
        printf("element doesn't exist");
    return (0);
}