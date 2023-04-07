#include "main.h"
#include <stdio.h>

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * otherwise return 0
 * @n: input
 * Return: 0 (if n < 0)
 */

int is_prime_number(int n)
{
	if (n <= 0)
	{
		return (0);
	}
	else
	{
		if ((n % (is_prime_number(n - 1))) == 0)
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
}
