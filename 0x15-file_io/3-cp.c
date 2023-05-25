#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define USE "Usage: cp file_from file_to\n"
#define READ "Error: Can't read from file %s\n"
#define WRITE "Error: Can't write to %s\n"
#define close "Can't close fd %d\n"
#define PER (O_WRONLY | O_CREAT | O_TRUNC)
#define PERS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH)
/**
 * main - copy
 * @v: pointer
 * @c: integer
 * Return: 1 (success)
 */
int main(int c, char **v)
{
	ssize_t a;
	int f = 0;
	int t = 0;
	char b[1024];

	if (c != 3)
		dprintf(STDERR_FILENO, USE);
		exit(97);
	f = open(v[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, READ, v[1]);
		exit(98);
	}
	t = open(v[2], PER, PERS);
	if (t == -1)
	{
		dprintf(STDERR_FILENO, WRITE, v[2]);
		exit(99);
	}
	while ((a = read(f, b, 1024)) > 0)
		if (write(t, b, a) != a)
		{
			dprintf(STDERR_FILENO, WRITE, v[2]);
			exit(99);
		}
	if (a == -1)
	{
		dprintf(STDERR_FILENO, READ, v[2]);
		exit(98);
	}
	f = close(f);
	t = close(t);
	if (f != NULL)
	{
		dprintf(STDERR_FILENO, CLOSE, f);
		exit(100);
	}
	if (t != NULL)
	{
		dprintf(STDERR_FILENO, CLOSE, f);
		exit(100);
	}
	return (EXIT_SUCCESS)
}
