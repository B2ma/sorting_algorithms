#include "sort.h"

/**
* swap_ints - Swap two integers in an array.
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
 * bubble_sort - A function that sorts an array in ascending order.
 * @array: the array to sort.
 * @size: the size to the array.
 * Description: prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len_of_arr = size;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < len_of_arr - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				swapped = true;
			}
		}
		len_of_arr--;
	}

}
