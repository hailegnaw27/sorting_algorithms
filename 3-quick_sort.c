#include "sort.h"

/**
 * swap_ints - Swaps two integer values
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Partitioning function for Quick Sort using Lomuto scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partition
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1;
    ssize_t j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap_ints(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }

    swap_ints(&array[i + 1], &array[high]);
    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}

/**
 * lomuto_quicksort - Recursive function for Quick Sort using Lomuto scheme
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void lomuto_quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot = lomuto_partition(array, low, high, size);

        lomuto_quicksort(array, low, pivot - 1, size);
        lomuto_quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Applies the quick sort algorithm on an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    lomuto_quicksort(array, 0, size - 1, size);
}
