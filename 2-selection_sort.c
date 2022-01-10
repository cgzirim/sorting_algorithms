#include "sort.h"

/**
 *selection_sort - implements the selection sort
 *                 on an array of integers
 *@array: the array of integers to sort
 *@size: the size of the array
 *
 *Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, min_index;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Find the min in the unsorted part of the array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		/* swap */
		tmp = array[i];
		array[i] = array[min_index];
		array[min_index] = tmp;

		/* print the array */
		print_array(array, size);
	}
}
