#include "main.h"
#include <stdio.h>

/** 
 * print_array - prints n elements of an array of integers
 * @a: array name
 * @n: is the number of elements of the array to be printed
 * Return: Always 0.
 */

void print_array(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n - 1; i++)
	{
		printf("%d, ", a[i]);
	}
	if (i == (n - 1))
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
