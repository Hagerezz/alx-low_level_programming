#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at index index of a list
 * @head: pointer
 * @index: index of the node that should be deleted
 * Returns: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node;
	listint_t *prev;
	unsigned int p = index - 1;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	prev = *head;
	while (prev != NULL && p != 0)
	{
		prev = prev->next;
		p--;
	}
	if (p != 0)
		return (-1);
	node = prev->next;
	prev->next = node->next;
	free(node);
	return (1);
}
