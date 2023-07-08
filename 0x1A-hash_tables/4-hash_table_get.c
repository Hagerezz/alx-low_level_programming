#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value
 * @ht: hash table
 * @key: key
 * Return: The value associated with the key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *t = NULL;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	t = ht->array[index];
	while (t != NULL)
	{
		if (strcmp(t->key, key) == 0)
			return (t->value);
		t = t->next;
	}
	return (NULL);
}
