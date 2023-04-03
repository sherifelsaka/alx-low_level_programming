#include "main.h"

/**
 * *_memset - fills memory with constant byte
 * @s: the pointer block of memory
 * @b: the value
 * @n: bytes of the memory
 * Return: pointer to the memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
