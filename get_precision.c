#include "main.h"

/**
 * get_precision - gets precision
 * @format: input char pointer
 * @i: lists of args to print
 * @list: list of args
 * Return: precision value
 */

int get_precision(const char *format, int *i, va_list list)
{
	int p = *i + 1;
	int precision = -1;

	if (format[p] != '.')
		return (precision);

	precision = 0;

	for (p += 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			precision *= 10;
			precision += format[p] - '0';
			p++;
		}
		else if (format[p] == '*')
		{
			p++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
		}

	*i = p - 1;

	return (precision);
}
