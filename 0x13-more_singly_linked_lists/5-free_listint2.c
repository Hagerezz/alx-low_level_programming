#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - frees a list
 * @head: pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *a = *head;
	listint_t *b;

	if (head == NULL)
		return;
	while (a != NULL)
	{
		b = a->next;
		free(a);
		a = b;
	}
	*head = NULL;
}
