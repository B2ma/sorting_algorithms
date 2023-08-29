#include "sort.h"


/**
 * l_partition - Order a subset of an array of integers based on
 *	lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset array.
 * @right: The ending index of the subset array.
 *
 * Return: partition index.
 */
int l_partition(int *array, size_t size, int left, int right)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_ints(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * l_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition.
 * @right: The ending index of the array partition.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void l_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = l_partition(array, size, left, right);
		l_sort(array, size, left, partition - 1);
		l_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	l_sort(array, size, 0, size - 1);
}
