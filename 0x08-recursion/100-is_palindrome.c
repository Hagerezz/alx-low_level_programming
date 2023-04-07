#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * palindrome - returns 1 if a string is a palindrome and
 * 0 if not
 * @s: input
 * @l: length of s
 * @p: position
 * Return: 1 (if a string is palindrome)
 */

int palindrome(char *s, int l, int p)
{
	if (l >= 2 * p)
		return (1);
	if (s[p] != s[l - p])
		return (0);
	return (palindrome(s, l, p + 1));
}

/**
 * is_palindrome - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int is_palindrome(char *s)
{
	int a = strlen(s);
	return (palindrome(s, a - 1, 0));
}
