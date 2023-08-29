#include "sort.h"

/**
* swap_ints - A function that swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
 * bit_merge - A function that sort a bitonic sequence
 * inside an array of integers.
 * @array: Array of integers to sort
 * @size: The size of the array.
 * @start: The index to start sorting from in a sequence in array.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t j, skip = seq / 2;

	if (seq > 1)
	{
		for (j = start; j < start + skip; j++)
		{
			if ((flow == UP && array[j] > array[j + skip]) ||
			    (flow == DOWN && array[j] < array[j + skip]))
				swap_ints(array + j, array + j + skip);
		}
		bit_merge(array, size, start, skip, flow);
		bit_merge(array, size, start + skip, skip, flow);
	}
}

/**
 * bit_seq - Convert an array of integers into a bitonic sequence.
 * @array: Array of integers to convert.
 * @size: The size of the array.
 * @start: The index to start sorting from in a bitonic sequence.
 * @seq: The size of a block of the building bit sequence.
 * @flow: The direction to sort in.
 */
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t halfed = seq / 2;
	char *string = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);

		bit_seq(array, size, start, halfed, UP);
		bit_seq(array, size, start + halfed, halfed, DOWN);
		bit_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - A function that sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: Array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_seq(array, size, 0, size, UP);
}
