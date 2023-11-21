#include "sort.h"

/**
 * counting_sort - Applies the counting sort algorithm on an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    size_t max_val = 0, i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if (array[i] > (int)max_val)
            max_val = array[i];
    }

    count_array = malloc((max_val + 1) * sizeof(int));
    if (!count_array)
        return;

    sorted_array = malloc(size * sizeof(int));
    if (!sorted_array)
    {
        free(count_array);
        return;
    }

    for (i = 0; i <= max_val; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    print_array(count_array, max_val + 1);

    for (i = 1; i <= max_val; i++)
        count_array[i] += count_array[i - 1];

    for (i = size - 1; i != (size_t)-1; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    free(count_array);
    free(sorted_array);
}
