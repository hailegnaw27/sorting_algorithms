#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into one sorted array
 * @array: The array to be sorted
 * @left: The left sub-array
 * @left_size: The size of the left sub-array
 * @right: The right sub-array
 * @right_size: The size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp_array;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    temp_array = malloc((left_size + right_size) * sizeof(int));
    if (!temp_array)
        return;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            temp_array[k] = left[i];
            i++;
        }
        else
        {
            temp_array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        temp_array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        temp_array[k] = right[j];
        j++;
        k++;
    }

    for (i = 0, k = 0; i < left_size + right_size && k < left_size + right_size; i++, k++)
        array[i] = temp_array[k];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(temp_array);
}

/**
 * merge_sort - Applies the merge sort algorithm on an array of integers
 * @array: The array to be sorted
 * @size: The size of thearray
 */
void merge_sort(int *array, size_t size)
{
    size_t mid = size / 2;
    size_t i;
    int *left, *right;

    if (!array || size < 2)
        return;

    left = malloc(mid * sizeof(int));
    if (!left)
        return;

    right = malloc((size - mid) * sizeof(int));
    if (!right)
    {
        free(left);
        return;
    }

    for (i = 0; i < mid; i++)
        left[i] = array[i];

    for (i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, mid, right, size - mid);

    free(left);
    free(right);
}
