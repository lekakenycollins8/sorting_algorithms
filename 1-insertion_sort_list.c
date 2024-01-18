#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the first node of list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			if (temp->prev != NULL)
			{
				temp->prev->next = temp;
			}
			else
			{
				*list = temp;
			}
			if (temp->next != NULL)
			{
				temp->next->prev = temp;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
