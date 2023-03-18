#include <stdio.h>

/**
 * main - prints the alphapet in lowercase,
 * follewed by a new line, except q and e
 * Return Always 0 (success)
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch != 'e' && ch != 'q')
		{
			putchar(ch);
		}
	}
	putchar('\n');
	return(0);
}
