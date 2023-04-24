#include "main.h"

/**
 * is_printable - Determines if a character is printable
 * @c: The character to evaluate
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int is_printable(char c)
{
    return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - Appends the ASCII code in hexadecimal format to a buffer
 * @buffer: The buffer to append to
 * @i: The starting index of the buffer
 * @ascii_code: The ASCII code to convert
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
    const char *hex_map = "0123456789ABCDEF";
    int high_nibble = ((unsigned char)ascii_code) >> 4;
    int low_nibble = ((unsigned char)ascii_code) & 0xF;
    buffer[i++] = '\\';
    buffer[i++] = 'x';
    buffer[i++] = hex_map[high_nibble];
    buffer[i] = hex_map[low_nibble];
    return (3);
}

/**
 * is_digit - Determines if a character is a digit
 * @c: The character to evaluate
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: The number to cast
 * @size: A value indicating the type to cast to
 *
 * Return: The casted value of num
 */
long int convert_size_number(long int num, int size)
{
    switch (size) {
        case S_LONG:
            return num;
        case S_SHORT:
            return (short) num;
        default:
            return (int) num;
    }
}

/**
 * convert_size_unsgnd - Casts an unsigned number to the specified size
 * @num: The number to cast
 * @size: A value indicating the type to cast to
 *
 * Return: The casted value of num
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
    switch (size) {
        case S_LONG:
            return num;
        case S_SHORT:
            return (unsigned short) num;
        default:
            return (unsigned int) num;
    }
}
