#include "main.h"
#include <stdlib.h>
/**
 * create_array - craete array of characters
 * @size: the size of the array
 * @c: initial value
 * Return: pointer to the array
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
