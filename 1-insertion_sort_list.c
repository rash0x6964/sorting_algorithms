#include "sort.h"

/**
 * swapNodes - swap two nodes of list
 *
 * @head: head of the list
 * @a: first node
 * @b: second node
 */

void swapNodes(listint_t **head, listint_t *a, listint_t *b)
{
	listint_t *temp;

	if (a == NULL || b == NULL || a == b)
		return;

	temp = a->prev;
	a->prev = b;
	b->prev = temp;

	a->next = b->next;
	b->next = a;

	if (a->prev != NULL)
		a->prev->next = a;
	else
		*head = a;

	if (a->next != NULL)
		a->next->prev = a;

	if (b->prev != NULL)
		b->prev->next = b;
	else
		*head = b;

	if (b->next != NULL)
		b->next->prev = b;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Insertion sort algorithm
 *
 * @list: doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current->prev;
		while (tmp && tmp->n > current->n)
		{
			swapNodes(list, tmp, current);
			print_list(*list);
			tmp = current->prev;
		}
		current = current->next;
	}
}
