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
    ssize_t a;
    int f = 0;
    int t = 0;
    char b[1024];

    if (argc != 3)
        dprintf(STDERR_FILENO, USE);
    exit(97);
    f = open(argv[1], O_RDONLY);
    if (f == -1)
    {
        dprintf(STDERR_FILENO, READ, argv[1]);
        exit(98);
    }
    t = open(argv[2], PER, PERS);
    if (t == -1)
    {
        dprintf(STDERR_FILENO, WRITE, argv[2]);
        exit(99);
    }
    while ((a = read(f, b, 1024)) > 0)
    {
        if (write(t, b, a) != a)
        {
            dprintf(STDERR_FILENO, WRITE, argv[2]);
            exit(99);
	}
    }
	if (a == -1)
	{
		dprintf(STDERR_FILENO, READ, argv[2]);
		exit(98);
	}
	f = close(f);
	t = close(t);
	if (f)
	{
		dprintf(STDERR_FILENO, CLOSE, f);
		exit(100);
	}
	if (t)
	{
	dprintf(STDERR_FILENO, CLOSE, f);
	exit(100);
	}
	return (EXIT_SUCCESS);
}
