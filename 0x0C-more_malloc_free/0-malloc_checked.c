#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * *malloc_checked - allocates memory using malloc
 * @b: input
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