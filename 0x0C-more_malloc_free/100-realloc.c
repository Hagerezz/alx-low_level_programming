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
	int i;
	void *h;

	if (ptr == NULL)
		return ((void *)malloc(new_size));
	if (new_size == 0)
		return (NULL);
	if (new_size == old_size)
		return (ptr);
	h = (void *)malloc(new_Size);
	for (i = 0; i < old_size && i < new_Size; i++)
		h[i] = ptr[i];
	return (h);
}
