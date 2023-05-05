#include <stdio.h>
#include "main.h"
/**
 * flip_bits  - returns the number of bits you would need to flip
 * @n: number
 * @m: number
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int res = 0, i;
	unsigned long int a = 1;
	unsigned long int b = n ^ m;

	for (i = 0; i < 64; i++)
	{
		if ((a << i) & b)
			res++;
	}
	return (res);
}
