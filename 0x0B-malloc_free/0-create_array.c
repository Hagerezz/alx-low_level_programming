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
	if (size == 0)
	{
		return (NULL);
	}
	char* a = malloc(size * sizeof(char));
	a[0] = c;
	return (a);
}
