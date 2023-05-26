#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - copy
 * @argv: pointer
 * @argc: integer
 * Return: 1 (success)
 */
int main(int argc, char *argv[])
{
	ssize_t b;
	int from = 0;
	int to = 0;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, USE);
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, READ, argv[1]);
		exit(98);
	}
	to = open(argv[2], PER, PERS);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, WRITE, argv[2]);
		exit(99);
	}
	while ((b = read(f, b, 1024)) > 0)
	{
		if (write(t, buf, b) != b)
		{
			dprintf(STDERR_FILENO, WRITE, argv[2]);
			exit(99);
		}
	}
	if (b == -1)
	{
		dprintf(STDERR_FILENO, READ, argv[2]);
		exit(98);
	}
	from = close(from);
	to = close(to);
	if (from)
	{
		dprintf(STDERR_FILENO, CLOSE, from);
		exit(100);
	}
	if (to)
	{
		dprintf(STDERR_FILENO, CLOSE, from);
		exit(100);
	}
	return (0);
}
