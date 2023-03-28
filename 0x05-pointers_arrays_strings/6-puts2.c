#include "main.h"
#include <stdio.h>

/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */

void puts2(char *str)
{
	char ch = str[0];
	int n = 0;

	while (ch != '\0')
	{
		if (n % 2 == 0)
			printf("%c", str[n]);
		ch = str[++n];
	}
	printf("\n");
}
