#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node
 * @head: pointer
 * @index: position
 * Return: NULL (node does not exist)
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	return (get_nodeint_at_index(head->next, index - 1));
}
