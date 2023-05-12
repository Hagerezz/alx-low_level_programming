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
	ssize_t r;
	char c[letters];

	if (filename == NULL || letters == 0)
		return (0);
	a = open(filename, O_RDONLY);
	if (a == -1)
		return (0);
	r = read(a, &c[0], letters);
	r = write(STDOUT_FILENO, &c[0], r);
	close(a);
	return (r);
}
