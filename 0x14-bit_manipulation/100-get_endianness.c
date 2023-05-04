#include "main.h"

/**
 * get_endianness - Checks the endianness of the machine.
 * Return: 0 if big endian, 1 if little endian.
 * Owner by Sherif Elsaka
 */
int get_endianness(void)
{
	unsigned int num = 0x12345678;
	char *ptr = (char *)&num;

	if (*ptr == 0x78)
		return (1);
	else
		return (0);
}
