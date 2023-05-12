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
	ssize_t len = strlen(text_content);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		b = write(file, text_content, len);
		if (b == -1)
		{
			close(file);
			return (-1);
		}
	}
	close(file);
	return (1);
}
