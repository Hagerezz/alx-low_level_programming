#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *create_array - creates an array of chars
 * and initializes it with a specific char
 * Return: NULL (if size = 0)
 */

char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size * sizeof(char));
	for (i = 0; i < size; i++)
		a[i] = c;
	return (a);
}
