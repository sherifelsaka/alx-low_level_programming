#include "main.h"

/* Function prototypes */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Constants */
#define MAX_BUFFER_SIZE 100

/* Functions */

/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    char num_str[MAX_BUFFER_SIZE];
    int num_len = 0;

    num = convert_size_unsgnd(num, size);

    do {
        num_str[num_len++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (flags & F_ZERO)
        precision = width - num_len;

    if (precision > num_len)
        width -= precision;

    if (!(flags & F_MINUS))
        while (width-- > num_len + precision)
            *buffer++ = (flags & F_ZERO) ? '0' : ' ';

    while (precision-- > num_len)
        *buffer++ = '0';

    while (num_len-- > 0)
        *buffer++ = num_str[num_len];

    while (width-- > num_len + precision)
        *buffer++ = ' ';

    return (buffer - buffer);
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    char num_str[MAX_BUFFER_SIZE];
    int num_len = 0;

    num = convert_size_unsgnd(num, size);

    do {
        num_str[num_len++] = (num % 8) + '0';
        num /= 8;
    } while (num > 0);

    if (flags & F_HASH && num_str[num_len - 1] != '0')
        num_str[num_len++] = '0';

    if (flags & F_ZERO)
        precision = width - num_len;

    if (precision > num_len)
        width -= precision;

    if (!(flags & F_MINUS))
        while (width-- > num_len + precision)
            *buffer++ = (flags & F_ZERO) ? '0' : ' ';

    while (precision-- > num_len)
        *buffer++ = '0';

    while (num_len-- > 0)
        *buffer++ = num_str[num_len];

    while (width-- > num_len + precision)
        *buffer++ = ' ';

    return (buffer - buffer);
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Flag character
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    char num_str[MAX_BUFFER_SIZE];
    int num_len = 0;

    num = convert_size_unsgnd(num, size);

    do {
        num_str[num_len++] = map_to[num % 16];
        num /= 16;
    } while (num > 0);

    if (flags & F_HASH && num_str[num_len - 1] != '0')
    {
        num_str[num_len++] = flag_ch;
        num_str[num_len++] = '0';
    }

    if (flags & F_ZERO)
        precision = width - num_len;

    if (precision > num_len)
        width -= precision;

    if (!(flags & F_MINUS))
        while (width-- > num_len + precision)
            *buffer++ = (flags & F_ZERO) ? '0' : ' ';

    while (precision-- > num_len)
        *buffer++ = '0';

    while (num_len-- > 0)
        *buffer++ = num_str[num_len];

    while (width-- > num_len + precision)
        *buffer++ = ' ';

    return (buffer - buffer);
}
