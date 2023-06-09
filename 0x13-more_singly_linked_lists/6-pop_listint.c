#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * pop_listint - deletes the head node of a listint
 * @head: pointer
 * Return: the head node’s data
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *a;

	if ((*head) == NULL)
		return (0);
	n = (*head)->n;
	a = (*head);
	(*head) = (*head)->next;
	free(a);
	return (n);
}
