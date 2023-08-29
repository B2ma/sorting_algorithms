#include "sort.h"


/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm, using the Knuth sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_ints(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
