#include "hash_tables.h"

/**
 * key_index - return the index
 * @key: pointer
 * @size: size
 * Return: the index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
