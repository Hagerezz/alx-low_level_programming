#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int a = 1;
	char *b = (char *) &i;

	return (*b);
}
