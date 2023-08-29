#include "sort.h"


/**
 * count_arraying_sort - Sort an array of integers in ascending order
 * using the count_arraying sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the count_arraying array after setting it up.
 */
void count_arraying_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, max_valu, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	max_valu = max_value(array, size);
	count_array = malloc(sizeof(int) * (max_valu + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max_valu + 1); i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;
	for (i = 0; i < (max_valu + 1); i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max_valu + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count_array);
}
