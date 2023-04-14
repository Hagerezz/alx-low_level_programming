#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *_realloc - reallocates a memory block
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pionter to the new allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *h;

	if (ptr == NULL)
		return ((void *)malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	h = (char *)malloc(new_size);
	for (i = 0; i < old_size && i < new_size; i++)
		h[i] = ((char *)ptr)[i];
	free(ptr);
	return ((void *)h);
}
