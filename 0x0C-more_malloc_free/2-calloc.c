#include "main.h"
#include <stdlib.h>
/**
 * *_calloc -  allocates memory for an array
 * @nmemb: nuber of elements in the array
 * @size: size of each element
 * Return: null (if malloc fail)
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *h;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	h = (char *)malloc(nmemb * size);
	if (h == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
		h[i] = 0;
	return ((void *)h);
}
