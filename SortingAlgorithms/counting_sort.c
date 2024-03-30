#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void counting_sort(int *arr, int len)
{
    int     i;
    int     j;
    int     count;
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
    i = 0;
    j = 0;
    count = 0;
    while (i <= max)
    {
        while (j != len)
        {
            if (arr[j] == i)
            {
                count++;
            }
            j++;
        }
        count_arr[i] = count;
        count = 0;
        j = 0;
        i++;
    }
    for (int i = 1; i <= max; i++) {
        count_arr[i] += count_arr[i - 1];
    }
    
    int *output_arr = (int *)malloc((len) * sizeof(int));
    if (!output_arr)
        return ;
    for (int i = len - 1; i >= 0; i--)
    {
        output_arr[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = output_arr[i];
    }
    free(count_arr);
    free(output_arr);
}

int main()
{
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int     len;

    len = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return (0);
}