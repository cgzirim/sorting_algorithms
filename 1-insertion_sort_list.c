#include "sort.h"

/**
 * insertion_sort_list - Implements Insertion sort on a doubly linked
 * list of integer values.
 * @list: The doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *left = *list;
	listint_t *right = (*list)->next;

	if ((*list)->next == NULL)
		return;

	while (right != NULL)
	{
		left = right->prev;
		while (left != NULL)
		{
			if (left->n > right->n)
			{
				/* Detatch*/
				left->next = right->next;
				if (right->next != NULL)
					right->next->prev = left;

				/* Swap*/
				right->next = left;
				right->prev = left->prev;
				left->prev = right;
				if (right->prev != NULL)
					right->prev->next = right;
				else
					*list = (*list)->prev;
				/* print list*/
				print_list(*list);
			}
			left = left->prev;
		}
		right = right->next;
	}
}
