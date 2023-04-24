#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 * Return: Precision.
 * Owner by Abdelrahman Sayed & Sherif Elsaka
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i + 1] != '.')
		return (precision);

	precision = 0;

	(*i)++;

	if (format[*i + 1] == '*')
	{
		(*i)++;
		precision = va_arg(list, int);
	}
	else
	{
		while (is_digit(format[*i + 1]))
		{
			precision = precision * 10 + (format[*i + 1] - '0');
			(*i)++;
		}
	}

	return (precision);
}
