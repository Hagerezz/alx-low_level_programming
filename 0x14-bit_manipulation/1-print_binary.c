#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	int b = 0;

	while (n >= (1 << (b + 1)))
		b++;
	while (b >= 0)
	{
		if (n >= (1 << b))
		{
			_putchar('1');
			n -= (1 << b);
		}
		else
			_putchar('0');
		b--;
	}
}
