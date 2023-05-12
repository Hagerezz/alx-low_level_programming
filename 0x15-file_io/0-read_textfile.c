#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * @filename: name of the file
 * @letters: the number of letters it should read and print
 * Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int a;
	ssize_t r, w;
	char c[letters];

	if (filename == NULL)
		return (0);
	a = open(filename, 'O_RONLY');
	if (a == -1)
		return (0);
	r = read(a, c, letters);
	if (r == -1)
	{
		close(a);
		return (0);
	}
	w = write(STDOUT_FILENO, c, r);
	if (w == -1 || w != r)
	{
		close(a);
		return (0);
	}
	close(a);
	return (w);
}
