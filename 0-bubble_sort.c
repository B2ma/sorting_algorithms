#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in the array.
 * @a: the first integer to swap.
 * @b: the second integer to swap with.
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - A function that sorts an array in ascending order.
 * @array: the array to sort.
 * @size: the size to the array.
 * Description: prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len_of_arr = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < len_of_arr - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len_of_arr--;
	}

}
