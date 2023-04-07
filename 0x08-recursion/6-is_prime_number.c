#include "main.h"
#include <stdio.h>

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * otherwise return 0
 * @n: input
 * Return: 0 (if n < 0)
 */

/**
 * is_prime - returns 1 if input is prime
 * @a: input
 * @b: input
 * @n: input
 * Return: 0 (if n is not prime
 */

int is_prime(int a, int b)
{
	if (b * b > a)
		return (1);
	if (a % b == 0)
		return (0);
	return (is_prime(a, b + 1));
}

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (is_prime(n, 2));
}
