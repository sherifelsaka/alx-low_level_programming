#include "main.h"
/**
 * malloc_checked - normal process termination
 * @b: allocated memory
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *i;

	i = malloc(b);
	if (i == NULL)
		exit(98);
	return (i);
}
