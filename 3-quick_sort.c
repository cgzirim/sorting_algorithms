#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing elements to be swapped.
 * @idx_a: The first element.
 * @idx_b: The second element.
 */
void swap(int *array, int idx_a, int idx_b)
{
	int tmp;

	tmp = array[idx_a];
	array[idx_a] = array[idx_b];
	array[idx_b] = tmp;
}

/**
 * partition - Pushes elements greater than a pivot to the
 *             right-hand-side of the pivot and elements less
 *             to the left in an array.
 * @array: The array.
 * @start: Starting index of the array.
 * @end: The last index of the array.
 *
 * Return: The current index of the pivot.
 */
int partition(int *array, int start, int end)
{
	int pivot, p_index, i;

	/* The pivote will be assigned to the last elem in the array*/
	pivot = array[end];
	p_index = start;

	/* Pushes them to the left side of p_index*/
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, i, p_index);
			p_index++; /* the p_index increases on every swap*/

		}
	}

	swap(array, p_index, end);
	/**
	 * p_index which will be used to divide the
	 * next subset of left and part of the array.
	 */
	return (p_index);
}



/**
 * sort - Sorts the left and right sides of a pivote.
 * @array: The array to sort.
 * @start: The start of the array.
 * @end: The end of the array.
 * @size: Size of the array.
 */
void sort(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int p_index;

		p_index = partition(array, start, end);
		print_array(array, size);
		sort(array, start, p_index - 1, size); /* sort the left side*/
		sort(array, p_index + 1, end, size); /* sort the right side*/
	}
}


/**
 * quick_sort - Implements Quick sort algorithm on an array of ints.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int start, end;

	start = 0;
	end = size - 1;
	sort(array, start, end, size);
}















