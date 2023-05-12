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
	ssize_t num;
	char *b;

	if (filename == NULL)
		return (0);
	if (letters == NULL)
		return (0);
	a = open(filename, O_RONLY);
	if (a == -1)
		return (0);
	b = malloc(sizeof(char) * (letters + 1));
	num = read(a, &b[0], letters);
	num = write(STDOUT_FILENO, &b[0], num);
	close(a);
	return (num);
}
