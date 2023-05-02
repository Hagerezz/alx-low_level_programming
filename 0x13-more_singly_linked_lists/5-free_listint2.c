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
	free(head);
}
