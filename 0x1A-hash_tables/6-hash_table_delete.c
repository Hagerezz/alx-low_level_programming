#include "hash_tables.h"

/**
 * hash_table_delete - Deletes  hash table
 * @ht: The hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *t = NULL, *next = NULL;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		t = ht->array[i];
		while (t != NULL)
		{
			next = t->next;
			free(t->key);
			free(t->value);
			free(t);
			t = next;
		}
	}
	free(ht->array);
	free(ht);
}
