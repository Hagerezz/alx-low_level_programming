#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_nodeint_end - adds a new node at the end of a list
 * @head: pointer
 * @n: new node
 * Return: the address of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a;
	listint_t *h;

	a = malloc(sizeof(listint_t));
	if (a == NULL)
		return (NULL);
	a->n = n;
	if (*head == NULL)
	{
		*head = a;
		return (a);
	}
	h = *head;
	while (h->next != NULL)
		h = h->next;
	h->next = a;
	return (a);
}
