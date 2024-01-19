#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes.
 * @node: node to swap.
 * @list: pointer to head of the list
 *
 * Return: node
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *left = node->prev, *curr = node;


	left->next = curr->next;
	if (curr->next)
		curr->next->prev = left;
	curr->next = left;
	curr->prev = left->prev;
	left->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}


/**
 * cocktail_sort_list - sorts a doubly linked list of integers.
 * @list: pointer to head of the list
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				curr = swap_nodes(curr->next, list);
				swapped = 1;
				print_list(*list);
			}
			curr = curr->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;

		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				curr = swap_nodes(curr, list);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}

	}
}
