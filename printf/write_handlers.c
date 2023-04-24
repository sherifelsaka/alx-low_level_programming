#include "main.h"

/**
 * handle_write_char - Writes a single character to the buffer
 * @c: The character to write
 * @buffer: The buffer to write to
 * @flags: The active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: The number of characters written
 */
int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size)
{
    int num_written = 0;
    char padding_char = (flags & F_ZERO) ? '0' : ' ';
    int padding_count = width - 1;

    if (padding_count < 0) {
        padding_count = 0;
    }

    if (flags & F_MINUS) {
        buffer[0] = c;
        for (int i = 1; i <= padding_count; i++) {
            buffer[i] = padding_char;
        }
        num_written = write(1, buffer, padding_count + 1);
    } else {
        for (int i = 0; i < padding_count; i++) {
            buffer[i] = padding_char;
        }
        buffer[padding_count] = c;
        num_written = write(1, buffer, padding_count + 1);
    }

    return num_written;
}

/**
 * write_number - Writes a number to the buffer
 * @is_negative: Whether the number is negative
 * @ind: The starting index of the buffer to write to
 * @buffer: The buffer to write to
 * @flags: The active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: The number of characters written
 */
int write_number(int is_negative, int ind, char buffer[],
                 int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padding_char = (flags & F_ZERO) ? '0' : ' ';
    char sign_char = 0;

    if (is_negative) {
        sign_char = '-';
    } else if (flags & F_PLUS) {
        sign_char = '+';
    } else if (flags & F_SPACE) {
        sign_char = ' ';
    }

    int num_written = write_num(ind, buffer, flags, width, precision,
                                length, padding_char, sign_char);

    return num_written;
}

/**
 * write_num - Writes a number to the buffer
 * @ind: The starting index of the number in the buffer
 * @buffer: The buffer to write to
 * @flags: The active flags
 * @width: The width specifier
 * @prec: The precision specifier
 * @length: The length of the number
 * @padd_char: The padding character
 * @extra_char: The extra character
 *
 * Return: The number of characters written
 */
int write_num(int ind, char buffer[],
              int flags, int width, int prec,
              int length, char padd_char, char extra_char)
{
    int num_written = 0;
    int padding_start = 1;
    int extra_char_count = (extra_char != 0) ? 1 : 0;

    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0) {
        return 0; /* printf(".0d", 0)  no char is printed */
    }

    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0') {
        buffer[ind] = padd_char = ' '; /* width is displayed with padding ' ' */
    }

    if (prec > 0 && prec < length) {
        padd_char = ' ';
    }

    while (prec > length) {
        buffer[--ind] = '0';
        length++;
    }

    if (extra_char != 0) {
        length++;
    }

    if (width > length) {
        int padding_count = width - length;
        for (int i = 1; i <= padding_count; i++) {
            buffer[i] = padd_char;
        }
        buffer[padding_count + 1] = '\0';

        if (flags & F_MINUS && padd_char == ' ') {
            if (extra_char != 0) {
                buffer[--ind] = extra_char;
            }
            num_written = write(1, &buffer[ind], length);
        } else if (!(flags & F_MINUS) && padd_char == ' ') {
            if (extra_char != 0) {
                buffer[--ind] = extra_char;
            }
            num_written = write(1, &buffer[1], padding_count) +
                          write(1, &buffer[ind], length);
        } else if (!(flags & F_MINUS) && padd_char == '0') {
            if (extra_char != 0) {
                buffer[--padding_start] = extra_char;
            }
            num_written = write(1, &buffer[padding_start], padding_count + extra_char_count) +
                          write(1, &buffer[ind], length - padding_count - extra_char_count);
        }
    } else {
        if (extra_char != 0) {
            buffer[--ind] = extra_char;
        }
        num_written = write(1, &buffer[ind], length);
    }

    return num_written;
}

/**
 * write_unsgnd - Writes an unsigned number to the buffer
 * @is_negative: Unused argument indicating if the number is negative
 * @ind: The starting index of the number in the buffer
 * @buffer: The buffer to write to
 * @flags: The active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: The number of characters written
 */
int write_unsgnd(int is_negative, int ind,
                 char buffer[],
                 int flags, int width, int precision, int size)
{
    int num_written = 0;
    int length = BUFF_SIZE - ind - 1;
    char padding_char = (precision > 0 && precision < length) ? ' ' : ' ';

    UNUSED(is_negative);
    UNUSED(size);

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0') {
        return 0; /* printf(".0d", 0)  no char is printed */
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS)) {
        padding_char = '0';
    }

    while (precision > length) {
        buffer[--ind] = '0';
        length++;
    }

    if (width > length) {
        int padding_count = width - length;
        for (int i = 0; i < padding_count; i++) {
            buffer[i] = padding_char;
        }
        buffer[padding_count] = '\0';

        if (flags & F_MINUS) {
            num_written = write(1, &buffer[ind], length) +
                          write(1, &buffer[0], padding_count);
        } else {
            num_written = write(1, &buffer[0], padding_count) +
                          write(1, &buffer[ind], length);
        }
    } else {
        num_written = write(1, &buffer[ind], length);
    }

    return num_written;
}

/**
 * write_pointer - Write a memory address
 * @buffer: The buffer to write to
 * @ind: The starting index of the number in the buffer
 * @length: The length of the number
 * @width: The width specifier
 * @flags: The active flags
 * @padding_char: The padding character
 * @extra_char: The extra character
 * @padding_start: The index at which padding should start
 *
 * Return: The number of characters written
 */
int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padding_char,
                  char extra_char, int padding_start)
{
    int num_written = 0;

    if (width > length) {
        int padding_count = width - length + 3;
        if (padding_count < 0) {
            padding_count = 0;
        }
        for (int i = 3; i < padding_count; i++) {
            buffer[i] = padding_char;
        }
        buffer[padding_count] = '\0';

        if (flags & F_MINUS && padding_char == ' ') {
            buffer[--ind] = 'x';
            buffer[--ind] = '0';
            if (extra_char) {
                buffer[--ind] = extra_char;
            }
            num_written = write(1, &buffer[ind], length) +
                          write(1, &buffer[3], padding_count - 3);
        } else if (!(flags & F_MINUS) && padding_char == ' ') {
            buffer[--ind] = 'x';
            buffer[--ind] = '0';
            if (extra_char) {
                buffer[--ind] = extra_char;
            }
            num_written = write(1, &buffer[3], padding_count - 3) +
                          write(1, &buffer[ind], length);
        } else if (!(flags & F_MINUS) && padding_char == '0') {
            if (extra_char) {
                buffer[--padding_start] = extra_char;
            }
            buffer[1] = '0';
            buffer[2] = 'x';
            num_written = write(1, &buffer[padding_start], padding_count - padding_start) +
                          write(1, &buffer[ind], length - (1 - padding_start) - 2);
        }
    } else {
        buffer[--ind] = 'x';
        buffer[--ind] = '0';
        if (extra_char) {
            buffer[--ind] = extra_char;
        }
        num_written = write(1, &buffer[ind], BUFF_SIZE - ind - 1);
    }

    return num_written;
}
