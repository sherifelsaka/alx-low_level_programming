#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * Return: Flags
 * Owner by Abdelrahman Sayed & Sherif Elsaka
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	const char FLAGS_CH[] = "-+0# ";
	const int FLAGS_ARR[] = { F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE };
	int j;

	for (j = 0; format[*i + 1] != '\0'; (*i)++)
	{
		for (j = 0; j < 5; j++)
		{
			if (format[*i + 1] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAGS_CH[j] == '\0')
			break;
	}

	return (flags);
}
