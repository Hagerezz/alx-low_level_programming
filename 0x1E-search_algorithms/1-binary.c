#include "search_algos.h"

/**
 * binary_search - do binary search
 * @array: pointer to array
 * @size: size of array
 * @value: value
 * Return: first index have the value
*/
int binary_search(int *array, size_t size, int value)
{
	size_t n;
	size_t i, j = 0;

	while (size > 0 && array)
	{
		n = (size - 1) / 2;
		printf("Searching in array: ");
		for (i = 0; i < size - 1; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("%d\n", array[size - 1]);
		if (value == array[n])
			return (n + j);
		else if (value < array[n])
		{
			size = n;
		}
		else if (value > array[n])
		{
			j += n + 1;
			size = size - n - 1;
			array += n + 1;
		}
	}
	return (-1);
}
