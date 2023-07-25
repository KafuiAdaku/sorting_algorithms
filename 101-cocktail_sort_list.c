#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_fwd - swaps two adjacent nodes of a doubly linked list in the forward
 *	      direction.
 * @head: pointer to the head of the list
 * @tail: pointer to the last node
 * @node: pointer to the node to swap
 * Return: nothing
 */

void swap_fwd(listint_t **head, listint_t **tail, listint_t **node)
{
	listint_t *next = (*node)->next;

	if ((*node)->prev != NULL)
		(*node)->prev->next = next;
	else
		*head = next;
	next->prev = (*node)->prev;
	(*node)->next = next->next;
	if (next->next !=  NULL)
		next->next->prev = *node;
	else
		*tail = *node;
	(*node)->prev = next;
	next->next = *node;
	*node = next;
}

/**
 * swap_bkw - swaps two adjacent nodes of a doubly linked list in the backward
 *	      direction.
 * @head: pointer to the head of the list
 * @tail: pointer to the last node
 * @node: pointer to the node to swap
 * Return: nothing
 */
void swap_bkw(listint_t **head, listint_t **tail, listint_t **node)
{
	listint_t *prev = (*node)->prev;

	if ((*node)->next != NULL)
		(*node)->next->prev = prev;
	else
		*tail = prev;
	prev->next = (*node)->next;
	(*node)->prev = prev->prev;
	if (prev->prev != NULL)
		prev->prev->next = (*node);
	else
		(*head) = *node;
	(*node)->next = prev;
	prev->prev = *node;
	*node = prev;

}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the cocktail shaker sort algorithm.
 * @list: pointer to the head of the array
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tail;
	int swap = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;

	current = *list;

	while (swap)
	{
		swap = 0;
		for (; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_fwd(list, &tail, &current);
				swap = 1;
				print_list((const listint_t *) *list);
			}
		}
		if (swap == 0)
			break;

		swap = 0;
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_bkw(list, &tail, &current);
				swap = 1;
				print_list((const listint_t *) *list);
			}
		}
	}
}
