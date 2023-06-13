#include <stdio.h>
#include "main.h"

/**
 * main - print number
 * @argc: number
 * @argv: array
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
