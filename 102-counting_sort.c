#include "sort.h"

/**
* max_value - A function that gets the largest value in an array of integers.
* @array: An array of integers.
* @size: The size of the array.
*
* Return: The largest value integer in the array.
*/
int max_value(int *array, int size)
{
int largets_value, i;

for (largets_value = array[0], i = 1; i < size; i++)
{
if (array[i] > largets_value)
largets_value = array[i];
}

return (largets_value);
}

/**
 * counting_sort - A function that sorts an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after sorting.
 */
void counting_sort(int *array, size_t size)
{
	int *sorted_array, *count_array, largets_value, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	largets_value = max_value(array, size);
	count_array = malloc(sizeof(int) * (largets_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (largets_value + 1); i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;
	for (i = 0; i < (largets_value + 1); i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, largets_value + 1);

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

