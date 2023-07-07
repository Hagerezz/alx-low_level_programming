#include "hash_tables.h"

/**
 * hash_table_create - create a new hash table
 * @size: size of the array
 * Return: a pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash = NULL;
	unsigned long int i;

	hash = malloc(sizeof(hash_table_t));
	if (hash == NULL)
		return (NULL);

	hash->array = malloc(sizeof(hash_node_t *) * size);
	if (hash->array == NULL)
	{
		return (NULL);
		free(hash);
	}
	for (i = 0; i < size; i++)
		hash->array[i] = NULL;
	hash->size = size;
	return (hash);
}
