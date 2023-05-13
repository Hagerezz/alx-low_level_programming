#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success
 */
int create_file(const char *filename, char *text_content)
{
	int file;
	ssize_t b;
	ssize_t len = 0;

	while (text_content != NULL && text_content[len] != '\0')
		len++;
	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);
	if (len != 0)
		b = write(file, text_content, len);
		close(file);
		return (b == len ? 1 : -1);
	else
		close(file);
		return (1);
}
