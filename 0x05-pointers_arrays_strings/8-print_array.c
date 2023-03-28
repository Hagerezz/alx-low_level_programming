#include "main.h"
#include <stdio.h>

/** print_array - Write a function that prints n elements of an array of integers,
 * followed by a new line
 *
 * Return: Always 0.
 */

void print_array(int *a, int n)
{
	int i = 0;
	
	for (i = 0; i < n - 1; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("%d\n", a[n - 1]);
}
