#include "search_algos.h"

/**
 * linear_search - do linear search
 * @array: pointer to array
 * @size: size of array
 * @value: value
 * Return: first index have the value
*/
int linear_search(int *array, size_t size, int value)
{
    size_t i = 0;

    for (i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            printf("Value checked array[%ld] = [%d]\n", i, array[i]);
            return (i);
        }
        else
            printf("Value checked array[%ld] = [%d]\n", i, array[i]);
    }
    return (-1);
}
