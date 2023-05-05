#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer
 * @index: index, starting from 0 of the bit you want to set
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a = 1, b = 0;

        if (index > 63)
                return (-1);
	a = a << index;
	b = b - 1;
        *n = *n & (a ^ b);
        return (1);
}
