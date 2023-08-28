#include "sort.h"

/**
 * swapNodesDll - swaps two adjacent nodes ofdoubly linked list
 * @list: doubly linked list
 * @near: the  node closer to head
 * @far: the node closer to tail
 */
void swapNodesDll(listint_t **list, listint_t *near, listint_t *far)
{
	listint_t *swap;

	if (near->prev)
		near->prev->next = far;
	else
		*list = far;
	if (far->next)
		far->next->prev = near;
	far->prev = near->prev;
	near->prev = far;
	swap = far;
	near->next = far->next;
	swap->next = near;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *	order using cocktail shaker sort algorithm
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	bool forward_swapped, backward_swapped;
	int shake_range = 1000000, num_checks;
	listint_t *current_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	current_node = *list;
	do {
		forward_swapped = backward_swapped = false;
		for (num_checks = 0; current_node->next && num_checks < shake_range;
				num_checks++)
		{
			if (current_node->next->n < current_node->n)
			{
				swapNodesDll(list, current_node, current_node->next);
				forward_swapped = true;
			}
			else
				current_node = current_node->next;
		}
		if (!current_node->next)
			shake_range = num_checks;
		if (forward_swapped)
			current_node = current_node->prev;
		shake_range--;
		for (num_checks = 0; current_node->prev && num_checks < shake_range;
				num_checks++)
		{
			if (current_node->n < current_node->prev->n)
			{
				swapNodesDll(list, current_node->prev, current_node);
				backward_swapped = true;
			}
			else
				current_node = current_node->prev;
		}
		if (backward_swapped)
		current_node = current_node->next;
	} while (forward_swapped || backward_swapped);
}
