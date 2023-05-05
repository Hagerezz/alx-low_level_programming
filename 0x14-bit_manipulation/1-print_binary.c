#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	long int b = 0;

	while (n >= (1 << (b + 1)))
		b++;
	while (b >= 0)
	{
		if (n >= (1 << b))
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
