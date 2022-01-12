#include "sort.h"

/**
 *bubble_sort - sorts an array of integers using the
 *              bubble sort algorithm
 *@array: the array of integers tp be sorted
 *@size: the size of the array
 *
 *Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, flag, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = size; i > 0; i--)
	{
		flag = 0;

		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag++;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
