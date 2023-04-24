#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * Return: Number of chars printed.
 */
int print_pointer(va_list types)
{
    char buffer[20];
    void *addrs = va_arg(types, void *);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    sprintf(buffer, "0x%lx", (unsigned long) addrs);
    return (write(1, buffer, strlen(buffer)));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * Return: Number of chars printed
 */
int print_non_printable(va_list types)
{
    char *str = va_arg(types, char *);
    char buffer[1024] = {0};
    int i, offset = 0, count = 0;

    if (str == NULL)
        return (write(1, "(null)", 6));

    for (i = 0; str[i] != '\0'; i++)
    {
        if (is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += sprintf(buffer + i + offset, "\\x%02x", str[i]);
    }

    return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types)
{
    char *str = va_arg(types, char *);
    int i, count = 0;

    if (str == NULL)
        str = ")Null(";

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
        count++;
    }

    return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types)
{
    char *str = va_arg(types, char *);
    char x;
    int i, j, count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    if (str == NULL)
        str = "(AHYY)";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }

    return (count);
}
