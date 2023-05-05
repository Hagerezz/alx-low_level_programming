#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	unsigned long int b = 0, i;

	while (n >= (1 << (b + 1)))
		b++;
	for (i = b + 1; i >= 1; i--)
	{
		if (n >= (1 << (i - 1)))
		{
			_putchar('1');
			n -= (1 << (i - 1));
		}
		else
			_putchar('0');
	}
}
