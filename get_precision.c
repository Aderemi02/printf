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
	int i = *i + 1;
	int precision = -1;

	if (format[i] != '.')
		return (precision);

	precision = 0;

	for (i += 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = i - 1;

	return (precision);
}
