#include "main.h"
#include <stdio.h>

/**
 * sqt - returns -1 if not complete square
 * else returns the value of the square root
 * @a: input
 * @b: input
 * Return: integer
 */

int sqt(int a, int b)
{
	if (b * b == a)
		return (b);
	if (b * b > a)
		return (-1);
	return (sqt(a, b + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input
 * Return: -1 (if n doesnot have a natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqt(n, 0));
}
