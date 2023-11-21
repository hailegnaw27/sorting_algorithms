#include "sort.h"

/**
 * shell_sort - Applies the shell sort algorithm using the Knuth sequence on an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    size_t i, j;
    int temp;

    if (!array || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    for (; gap > 0; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;

            print_array(array, size);
        }
    }
}
