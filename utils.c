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
 * max_value - Get the largest value in an array of integers.
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
