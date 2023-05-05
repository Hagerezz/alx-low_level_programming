#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: number
 * @index: is the index, starting from 0 of the bit you want to get
 * Return: the value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	return ((n >> index) & 1);
}
