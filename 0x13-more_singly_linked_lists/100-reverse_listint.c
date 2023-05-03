#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * reverse_listint - reverses a listint_t
 * @head: pointer
 * Return: a pointer to the first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next;
	listint_t *node;
	listint_t *prev;

	node = *head;
	prev = node->next;
	node->next = NULL;
	if (prev == NULL)
		return (node);
	while (prev != NULL)
	{
		next = prev;
		prev = prev->next;
		next->next = node;
	}
	*head = next;
	return (next);
}
