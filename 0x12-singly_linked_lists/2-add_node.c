#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * *add_node - adds a new node at the beginning of a list
 * @head: double pointer to the list
 * @str: new string to add the node in it
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node = malloc(sizeof(list_t));
	
	if (node == NULL)
		return (NULL);
	node->next = *head;
	node->len = strlen(str);
	node->str = strdup(str);
	head = &node;
	return (node);
}
