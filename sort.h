#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

/**
 * enum bool - Boolean values enumeration.
 * @false: 0.
 * @true: 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

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

void swap_ints(int *a, int *b);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swapNodesDll(listint_t **list, listint_t *near, listint_t *far);
void subarrayMerge(int *subarray, int *buffer, size_t l_band, size_t middle,
		size_t u_band);
void mergeSortRecursive(int *subarray, int *buffer, size_t l_band,
		size_t u_band);
int max_val(int *array, int size);
void countingSort(int *array, size_t size, int s_digit, int *buffer);
int hoare_partition(int *array, size_t size, int start, int end);
void hoare_sort(int *array, size_t size, int start, int end);

int l_partition(int *array, size_t size, int left, int right);
void l_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bit_merge(int *array, size_t size, size_t start, size_t seq,
char flow);
void sift_down(int *array, size_t size, size_t b_index, size_t root_node);


#endif
