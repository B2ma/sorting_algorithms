#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIdx;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
		minIdx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIdx])
				minIdx = j;
		}

		if (minIdx != i)
		{
			swap_ints(&array[i], &array[minIdx]);
			print_array(array, size);
		}
	}
}
