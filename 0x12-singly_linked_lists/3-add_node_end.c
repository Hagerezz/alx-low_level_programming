#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_node_end - adds a new node at the end of a list
 * @head: double pointer to the list
 * @str: string to put the node in it
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tail;

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	node->next == NULL;
	node->len = strlen(str);
	node->str = strdup(str);
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	tail = *head->next;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = node;
	return (node);
}
