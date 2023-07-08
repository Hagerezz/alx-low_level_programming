#include "hash_tables.h"

/**
 * shash_table_create - Creates
 * @size: The size
 * Return: pointer
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i = 0;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->size = size;
	return (ht);
}

/**
 * shash_table_set - Inserts a key/value
 * @ht: sorted hash table
 * @key: key string.
 * @value: value string.
 * Return: 1 (success)
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node = NULL, *t = NULL;

	if (ht == NULL || key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	t = ht->array[index];
	while (t != NULL)
	{
		if (strcmp(t->key, key) == 0)
		{
			free(t->value);
			t->value = strdup(value);
			return (1);
		}
		t = t->next;
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[index];
	ht->array[index] = node;
	if (ht->shead == NULL)
	{
		ht->shead = node;
		node->sprev = NULL;
		node->snext = NULL;
	}
	else if (strcmp(key, ht->shead->key) < 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(key, ht->stail->key) > 0)
	{
		node->sprev = ht->stail;
		node->snext = NULL;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		t = ht->shead;
		while (t != NULL)
		{
			if (strcmp(key, t->key) < 0)
			{
				node->sprev = t->sprev;
				node->snext = t;
				t->sprev->snext = node;
				t->sprev = node;
				break;
			}
			t = t->snext;
		}
	}
	return (1);
}

/**
 * shash_table_get - Retrieves the value associated
 * @ht: sorted hash table
 * @key: key string.
 * Return: The value associated with the key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node = NULL;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *) key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;

	if (ht == NULL)
		return;
	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints sorted hash table in reverse order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;

	if (ht == NULL)
		return;
	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 *
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node = NULL, *t = NULL;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			t = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = t;
		}
	}
	free(ht->array);
	free(ht);
}
