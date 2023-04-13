#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * *string_nconcat - concatenates two strings
 * @s1: string to append to
 * @s2: string to concatenates from
 * @n: number of s2 to concatenate to s1
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int l1 = 0, l2 = 0, i;
	char *p;

	while (s1 != NULL && s1[l1] != '\0')
		l1++;
	while (s2 != NULL && s2[l2] != '\0' && l2 < n)
		l2++;
	p = (char *)malloc((l1 + l2) * sizeof(char))
	if (p == NULL)
		return (NULL);
	for (i = 0; i < l1; i++)
		p[i] = s1[i];
	for (i = 0; i < l2; i++)
		p[i + l1] = s2[i];
	p[l1 + l2] = '\0';
	return (p);
}
