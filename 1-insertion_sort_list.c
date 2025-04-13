#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @tmp: The left node
 * @tmp2: The right node
 */
void swap_nodes(listint_t **list, listint_t *tmp, listint_t *tmp2)
{
	if (tmp->prev)
		tmp->prev->next = tmp2;
	else
		*list = tmp2;
	if (tmp2->next)
		tmp2->next->prev = tmp;
	tmp2->prev = tmp->prev;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list)
	{
		for (i = (*list)->next; i != NULL; i = i->next)
		{
			j = i;
			while (j->prev && j->prev->n > j->n)
			{
				swap_nodes(list, j->prev, j);
			}
		}
	}
}
