#include "maih.h"

/**
 * get_width - gets width to print
 * @format: input char pointer
 * @i: lists of args to print
 * @list: list of args
 * Return: width value
 */

int get_width(const char *format, int *i, va_list list)
{
	int i;
	int width = 0;

	for (i = *i + 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			width *= 10;
			width += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = i - 1;

	return (width);
}
