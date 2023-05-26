#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define USE "Usage: cp file_from file_to\n"
#define READ "Error: Can't read from file %s\n"
#define WRITE "Error: Can't write to %s\n"
#define CLOSE "Error: Can't close fd %d\n"
#define PER (O_WRONLY | O_CREAT | O_TRUNC)
#define PERS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
#endif
