#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * *add_node_end - adds a new node at the end of a list
 * @head: double pointer to the list
 * @str: string to put the node in it
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node;

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
	return (add_tail(*head, node));
}
/**
 * *add_tail - add to yhe tail
 * @node: pointer to node in the list
 * @tail: pointer to the tail in the list
 * Return: pointer to the tail
 */
list_t *add_tail(list_t *node, list_t *tail)
{
	if (node->next == NULL)
	{
		node->next = tail;
		return (tail);
	}
	return (add_tail(node->next, tail));
}
