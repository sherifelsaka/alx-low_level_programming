#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - function search a string
 * @accept: match one of byte
 * @s: first occurrence
 * Return: a pointer to byte
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (NULL);
}
