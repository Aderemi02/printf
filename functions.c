#include "main.h"

/**
 * print_char - prints char
 * @types: types of args
 * @buffer: buffer array
 * @flags: calculate flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of chars
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
