#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *creat(char *f);
void clos(int a);

/**
 * create_buffer - Allocate
 * @f: pointer
 * Return: pointer
 */
char *creat(char *f)
{
	char *b = malloc(sizeof(char) * 1024);

	if (!b)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f);
		exit(99);
	}
	return (b);
}
/**
 * clos - Close
 * @a: integer
 */
void clos(int a)
{
	int d = close(a);

	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", a);
		exit(100);
	}
}
/**
 * main - copy
 * @c: number
 * @v: pointer
 * Return: 0 (success)
 */
int main(int c, char *v[])
{
	int w;
	char *b = creat(v[2]);
        int f = open(v[1], O_RDONLY);
        int r = read(f, b, 1024);
        int o = open(v[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (c != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", v[1]);
			free(b);
			exit(98);
		}

		w = write(o, b, r);
		if (o == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", v[2]);
			free(b);
			exit(99);
		}

		r = read(f, b, 1024);
		o = open(v[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(b);
	clos(f);
	clos(o);
	return (0);
}
