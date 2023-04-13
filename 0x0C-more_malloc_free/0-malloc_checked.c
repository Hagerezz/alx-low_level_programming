#include "main.h"
#include <stdlib.h>

/*
 * *malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 * Return: pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *r;

	r = malloc(b);

	if (r == NULL)
		exit(98);
	return (r);
}
