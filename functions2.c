#include "main.h"

/**
 * print_pointer - prints a pointer
 * @types: types of args
 * @buffer: buffer array
 * @flags: calculate flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: pointer to number of chars
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0;
	char pad = ' ';
	int index = BUFF_SIZE - 2, pad_start = 1, len = 2;
	char map_to[] = "0123456789abcdef";
	unsigned long num_adrs;
	void *adrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nul)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_adrs = (unsigned long)adrs;

	while (num_adrs > 0)
	{
		buffer[index--] = map_to[num_adrs % 16];
		num_adrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	index++;

	return (write_pointer(buffer, index, len, width,
				flags, pad, extra_c, pad_start));
}

/**
 * print_non_printable - prints ascii codes in hexa
 *  * @types: types of args
 * @buffer: buffer array
 * @flags: calculate flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of chars
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	int offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints reverse of a string
 *  * @types: types of args
 * @buffer: buffer array
 * @flags: calculate flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i;
	int count = 0;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: types of args
 * @buffer: buffer array
 * @flags: calculate flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of char
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

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
