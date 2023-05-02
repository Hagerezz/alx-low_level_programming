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
	free_list(*head);
	free(head);
}

void free_list(listint_t *h)
{
	if (h != NULL)
	{
		free_list(h->next);
		free(h);
	}
}
