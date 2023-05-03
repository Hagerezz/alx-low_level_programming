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

	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	a = *head;
	*head = (*head)->next;
	a->next = NULL;
	while ((*head) != NULL)
	{
		b = *head;
		*head = (*head)->next;
		b->next = a;
		a = b;
	}
	*head = a;
	return (a);
}
