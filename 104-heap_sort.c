#include "sort.h"

/**
 * sift_down - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @b_index: The index of the base row of the tree.
 * @root_node: The base node of the binary tree.
 */
void sift_down(int *array, size_t size, size_t b_index, size_t root_node)
{
	size_t left_node, right_node, large;

	left_node = 2 * root_node + 1;
	right_node = 2 * root_node + 2;
	large = root_node;

	if (left_node < b_index && array[left_node] > array[large])
		large = left_node;
	if (right_node < b_index && array[right_node] > array[large])
		large = right_node;

	if (large != root_node)
	{
		swap_ints(array + root_node, array + large);
		print_array(array, size);
		sift_down(array, size, b_index, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * using sift_down heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		sift_down(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		sift_down(array, size, j, 0);
	}
}
