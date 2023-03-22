#include <stdio.h>

/**
 * main - Prints first 50 Fibonacci numbers, starting with 1 and 2,
 *        separated by a comma followed by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long a = 0, b = 1, c;

	for (i = 0; i < 50; i++)
	{
		c = a + b;
		printf("%lu", c);

		a = b;
		b = c;

		if (c == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}

