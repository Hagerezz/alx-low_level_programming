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
	listint_t *a;
	listint_t *b;
	listint_t *c;

	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*next);
	a = *head;
	b = a->next;
	while (b != NULL)
	{
		c = b;
		b = b->next;
		c->next = a;
		a = c;
	}
	*head = a;
	return (a);
}
