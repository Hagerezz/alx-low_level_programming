#include "main.h"
#include <stdio.h>

int _strlen_recursion(char *s);

/**
 * is_palindrome - returns 1 if a string is a palindrome and
 * 0 if not
 * @s: input
 * Return: 1 (if a string is palindrome)
 */

int is_palindrome(char *s)
{
	
}

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	int a = 0;

	if (*s)
	{
		a++;
		a += _strlen_recursion(s + 1);
	}
	return (a);
}
