#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *creat_clos(char *f, int a);
/**
 * creat_clos - allocate and close
 * @f: pointer
 * @a: file
 * Return: pointer
 */
char *creat_clos(char *f, int a)
{
	char *b = malloc(sizeof(char) * 1024);
	int c = close(a);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f);
		exit(99);
	}
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", a);
		exit(100);
	}
	return (b);
}
/**
 * main - copy
 * @x: number
 * @y: pointer
 * Return: 0 (success)
 */
int main(int x, char *y[])
{
	char *b = creat_clos(y[2]);
	int f = open(y[1], O_RDONLY);
	int r = read(f, b, 1024);
	int o = open(y[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	int w = write(o, b, r);

	if (x != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	while (1)
	{
		if (r == -1 || f == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", y[1]);
			free(b);
			exit(98);
		}
		if (r == 0)
			break;

		o = open(y[2], O_WRONLY | O_APPEND);

		if (o == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", y[2]);
			free(b);
			exit(99);
		}
	}
	free(b);
	creat_clos(f);
	creat_clos(o);
	return (0);
}
}
