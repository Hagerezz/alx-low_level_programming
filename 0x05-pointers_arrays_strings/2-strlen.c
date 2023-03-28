#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	char ch = s[0];
	int n = 0;

	while (ch != '\0')
		ch = s[++n];
	return (n);
}
