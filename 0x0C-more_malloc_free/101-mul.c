#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *s1, *s2;
	int *digit1, *digit2, *res;
	int i, j;

	s1 = argv[1];
	s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
	{
		printf("Error\n");
		exit(98);
	}
	digit1 = (int *)malloc(sizeof(int) * strlen(s1));
	digit2 = (int *)malloc(sizeof(int) * strlen(s2));
	res = (int *)malloc(sizeof(int) * (strlen(s2) + strlen(s1) - 1));
	for (i = 0; i < strlen(s1) + strlen(s2) - 1; i++)
		res[i] = 0;
	for (i = 0; i < strlen(s1); i++)
		digit1[i] = s1[i] - '0';
	for (i = 0; i < strlen(s2); i++)
		digit2[i] = s2[i] - '0';
	for (i = strlen(s1) - 1; i >= 0; i--)
	{
		for (j = strlen(s2) - 1; j >= 0; j--)
			res[i + j] += digit1[i] * digit2[j];
	}
	for (i = strlen(s1) + strlen(s2) - 2; i > 0; i--)
	{
		res[i - 1] += res[i] / 10;
		res[i] /= 10;
	}
	for (i = 0; i < strlen(s1) + strlen(s2) - 1; i++)
		printf("%d",res[i]);
	printf("\n");
	return (0);
}
