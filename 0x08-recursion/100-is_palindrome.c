#include "main.h"
#include <stdio.h>

int _strlen_recursion(char *s);

/**
 * is_palindrome - returns 1 if a string is a palindrome and
 * 0 if not
 * @s: input
 * Return: 1 (if a string is palindrome)
 */

int is_palindrome(char *s, int l, int p)
{
	if (l => 2 * p)
		return (1);
	if (s[p] != s[l - p])
		return (0);
	return (is_palindrome(s, l, p + 1));
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
	return (is_palindrome(s, a - 1, 0));
}
