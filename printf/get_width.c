#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Index of the current character in the format string
 * @list: List of arguments
 * Return: Width
 * Owner by Abdelrahman Sayed & Sherif Elsaka
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	while (format[*i + 1] != '\0')
	{
		if (is_digit(format[*i + 1]))
		{
			width = width * 10 + (format[*i + 1] - '0');
			(*i)++;
		}
		else if (format[*i + 1] == '*')
		{
			width = va_arg(list, int);
			(*i)++;
			break;
		}
		else
		{
			break;
		}
	}

	return (width);
}
