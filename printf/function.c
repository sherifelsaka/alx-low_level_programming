#include "main.h"

/**
 * print_char - Prints a character
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_char(va_list types)
{
	char c = va_arg(types, int);
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_string(va_list types)
{
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	return (write(1, str, _strlen(str)));
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_percent(va_list types)
{
	return (write(1, "%", 1));
}

/**
 * print_int - Prints an integer
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_int(va_list types)
{
	long int n = va_arg(types, long int);
	int is_negative = n < 0;
	unsigned long int num = is_negative ? -n : n;
	char buffer[BUFF_SIZE];
	int i = 0;

	if (num == 0)
		buffer[i++] = '0';

	while (num != 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}

	if (is_negative)
		buffer[i++] = '-';

	return (write_number(buffer, i));
}

/**
 * print_binary - Prints a binary number
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_binary(va_list types)
{
	unsigned int n = va_arg(types, unsigned int);
	char buffer[32];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';

	while (n != 0)
	{
		buffer[i++] = n % 2 + '0';
		n /= 2;
	}

	return (write_number(buffer, i));
}

/**
 * write_number - Writes a number to stdout
 * @buffer: Buffer containing the number to write
 * @length: Length of the buffer
 * Return: Number of characters printed
 */
int write_number(char *buffer, int length)
{
	int count = 0;

	while (length-- > 0)
		count += write(1, buffer + length, 1);

	return (count);
}

/**
 * _strlen - Computes the length of a string
 * @str: The string to compute the length of
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
