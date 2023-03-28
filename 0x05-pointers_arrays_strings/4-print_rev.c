#include "main.h"
#include <stdio.h>

/**
 * print_rev -  prints a string, in reverse,
 * followed by a new line.
 * @s: string
 * Return: Always 0
 */

void print_rev(char *s)
{
	char ch = s[0];
	int i;
	int n = 0;

	while (ch != '\0')
	{
	ch = s[++n];
	}
	for (i = (n - 1); i => 0; i--)
	{
		printf("%c", s*);
	}
	printf("\n");
}
