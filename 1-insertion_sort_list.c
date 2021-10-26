#include "sort.h"
/**
 * insertion_sort_list - Sort
 * @list: list
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *change = NULL, *change2 = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		change = current->prev;
		change2 = current;
		current = current->next;
		while (change != NULL)
		{
			if (change->n > change2->n)
			{
				if (change->prev != NULL)
					change->prev->next = change2;
				else if (change->prev == NULL)
				{
					*list = change;
				}
				if (change2->next != NULL)
					change2->next->prev = change;
				change->next = change2->next;
				change2->prev = change->prev;
				change->prev = change2;
				change2->next = change;
				change = change2->prev;
				if (change2->prev == NULL)
					*list = change2;
				print_list(*list);
			}
			else
			{
				change2 = change;
				change = change->prev;
			}
		}
	}
}
