#include "sort.h"

/**
 * swap_node - swaps two adjacent nodes of a doubly linked list
 * @head: pointer to the head of the list
 * @prev: pointer to the fisrt node
 * @curr: pointer to the second
 * Return: nothing
 */

void swap_node(listint_t **head, listint_t **prev, listint_t *curr)
{
	listint_t *prev_tmp = *prev;

	if (prev)
		(*prev)->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = *prev;
	curr->next = prev_tmp;
	curr->prev = prev_tmp->prev;

	if (prev_tmp->prev != NULL)
		(*prev)->prev->next = curr;
	else
		*head = curr;
	prev_tmp->prev = curr;
	*prev = curr;
}
/**
 * insertion_sort_list - sorts an array of integer in an ascending order
 *			 using insertion sort algorithm
 * @list: pointer to the head of of the list.
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			prev = tmp->prev;
			print_list(*list);
			swap_node(list, &prev, tmp);
			print_list(*list);
		}
		current = current->next;
	}
}
