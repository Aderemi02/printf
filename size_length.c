#include "main.h"

/**
 * get_size - finds the size to cast the argument
 * @format: Formatted string, list of arguments the arguments
 * @i: List of arguments to be printed.
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int cumm = *i + 1;
	int size = 0;

	if (format[cumm] == 'l')
		size = S_LONG;
	else if (format[cumm] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cumm - 1;
	else
		*i = cumm;

	return (size);
}
