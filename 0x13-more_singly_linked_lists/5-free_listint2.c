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
	listint_t *b;

	if (head == NULL)
		return;
	while ((*head) != NULL)
	{
		b = (*head)->next;
		free((*head));
		(*head) = b;
	}
	*head = NULL;
}
