#include "sort.h"


/**
 * hoare_partition - Orders subset of array based on hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of array.
 * @start: start index of array subset.
 * @end: end index of array subset.
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int start, int end)
{
	int pivot, upper, lower;

	pivot = array[end];
	for (upper = start - 1, lower = end + 1; upper < lower;)
	{
	do {
		upper++;
	} while (array[upper] < pivot);
	do {
		lower--;
	} while (array[lower] > pivot);

	if (upper < lower)
	{
		swap_ints(array + upper, array + lower);
		print_array(array, size);
	}
	}

return (upper);
}

/**
 * hoare_sort - Does the quicksort algorithm recursively by
 *	Hoare partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: start index of array subset.
 * @end: end index of array subset.
 */
void hoare_sort(int *array, size_t size, int start, int end)
{
	int partition;

	if (end - start > 0)
	{
		partition = hoare_partition(array, size, start, end);
		hoare_sort(array, size, start, partition - 1);
		hoare_sort(array, size, partition, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *	order using the quicksort algorithm and Hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
