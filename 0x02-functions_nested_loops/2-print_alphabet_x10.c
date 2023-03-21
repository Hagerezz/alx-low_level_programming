#include "main.h"

/**
 * main - prints 10 times the alphabet in lowercase,
 * followed by a new line.
 *
 * Return: Always 0
 */

void print_alphabet_x10(void)
{
	int i;
	char a;

	for (i = 0; i < 10; i ++)
	{
		for (ch = 'a'; ch <= 'z'; ch ++)
		{
			_putchar(a);
		}
		_putchar('\n');
	}
}
