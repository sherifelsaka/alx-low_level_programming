#include "main.h"

/**
 * _memcpy - copy memory areas
 * @n: no of bytes to be copied
 * @src: memory area to copy
 * @dest: destination memory area
 * Return: return to destenation
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
