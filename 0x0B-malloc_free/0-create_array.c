#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *create_array - creates an array of chars
 * and initializes it with a specific char
 * @size: size of array
 * @c: char to as sign
 * Return: NULL (if size = 0)
 */

char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int i;

	a = malloc(size * sizeof(char));
	if (size == 0 || a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		a[i] = c;
	return (a);
}
