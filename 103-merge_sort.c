#include "sort.h"

/**
 * subarrayMerge - Sort a subarray of integers.
 * @subarray: A subarray of an array.
 * @buffer: A buffer to store sorted subarray.
 * @l_band: The lower bound index of the array.
 * @middle: The middle index of the array.
 * @u_band: The upper bound index of the array.
 */
void subarrayMerge(int *subarray, int *buffer, size_t l_band, size_t middle,
size_t u_band)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + l_band, middle - l_band);

	printf("[right]: ");
	print_array(subarray + middle, u_band - middle);

	for (i = l_band, j = middle; i < middle && j < u_band; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < middle; i++)
		buffer[k++] = subarray[i];
	for (; j < u_band; j++)
		buffer[k++] = subarray[j];
	for (i = l_band, k = 0; i < u_band; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + l_band, u_band - l_band);
}

/**
 * mergeSortRecursive - does merge sort algorithm recursively.
 * @subarray: A subarray of an array.
 * @buffer: A buffer to store the sorted subarray.
 * @l_band: The lower bound index of subarray.
 * @u_band: The upper bound index of subarray.
 */
void mergeSortRecursive(int *subarray, int *buffer, size_t l_band,
		size_t u_band)
{
	size_t middle;

	if (u_band - l_band > 1)
	{
		middle = l_band + (u_band - l_band) / 2;
		mergeSortRecursive(subarray, buffer, l_band, middle);
		mergeSortRecursive(subarray, buffer, middle, u_band);
		subarrayMerge(subarray, buffer, l_band, middle, u_band);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	mergeSortRecursive(array, buffer, 0, size);

	free(buffer);
}
