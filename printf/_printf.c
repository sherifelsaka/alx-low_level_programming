#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 *
 * @buffer: Array of characters.
 * @buff_ind: Pointer to index at which to add the next character.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

/**
 * _printf - Custom version of the standard printf function.
 *
 * @format: Format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        return (-1);
    }

    int printed_chars = 0;
    int buffer_index = 0;
    char buffer[BUFF_SIZE];

    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);

            int printed = handle_print(format, &i, args, buffer, flags, width, precision, size);
            if (printed == -1)
            {
                va_end(args);
                return (-1);
            }

            printed_chars += printed;
            buffer_index = 0;
        }
        else
        {
            if (buffer_index == BUFF_SIZE)
            {
                print_buffer(buffer, &buffer_index);
            }

            buffer[buffer_index] = format[i];
            buffer_index++;
            printed_chars++;
        }
    }

    print_buffer(buffer, &buffer_index);
    va_end(args);

    return (printed_chars);
}
