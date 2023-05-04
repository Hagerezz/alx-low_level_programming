#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	unsigned int b = 1;

	if (n == 0 || n == 1)
		printf("%ld\n, n");
	while (n >= (1 << b))
		b++;
	b--;
	while (b >= 0)
	{
		if (n - (1 << b) >= 0)
		{
			printf("1");
			n -= (1 << b);
		}
		else
			printf("0");
		b--;
	}
	printf("\n");
}
