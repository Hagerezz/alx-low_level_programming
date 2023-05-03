#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node
 * @head: pointer
 * @idx: index
 * @n: new node to be added
 * Return: the address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new;
	listint_t *prev;
	unsigned int p = idx - 1;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	prev = *head;
	while (prev != NULL && p != 0)
	{
		prev = prev->next;
		p--;
	}
	if (p != 0)
		return (NULL);
	new->next = prev->next;
	prev->next = new;
	return (new);
}
