#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void counting_sort(int *arr, int len, int digit)
{
    int     i;
    int     max;

    i = 1;
    max = arr[0];
    while (i != len)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        i++;
    }
    int *count_arr = (int *)malloc((max + 1) * sizeof(int));
    if (!count_arr)
        return ;
    for (int i = 0; i < max; i++) {
        count_arr[i] = 0;
    }
    i = 0;
    for (i = 0; i < len; i++)
        count_arr[(arr[i] / digit) % 10]++;
    for (int i = 1; i < max; i++) {
        count_arr[i] += count_arr[i - 1];
    }
    
    int *output_arr = (int *)malloc((len) * sizeof(int));
    if (!output_arr)
        return ;
    for (int i = len - 1; i >= 0; i--)
    {
        output_arr[count_arr[(arr[i] / digit) % 10] - 1] = arr[i];
        count_arr[(arr[i] / digit) % 10]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = output_arr[i];
    }
    free(count_arr);
    free(output_arr);
}

void radix_sort(int *arr, int len)
{
    int     i;
    int     max;

    i = 1;
    max = arr[0];
    while (i != len)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        i++;
    }
    for (int digit = 1; max / digit > 0; digit *= 10)
        counting_sort(arr, len, digit);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    radix_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}