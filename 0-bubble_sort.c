#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using the
*               Bubble Sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int tmp;
int swaped;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
swaped = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
swaped = 1;
print_array(array, size);
}
}

if (swaped == 0)
break;
}
}
