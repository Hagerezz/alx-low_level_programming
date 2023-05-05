#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	unsigned long int i = 1;

	while (n > i)
	{
		i = i << 1;
	}
	while (i > 0)
	{
		if (n & i)
		{
			_putchar('1');
		}
		else
			_putchar('0');
		i = i >> 1;
	}
}
