#include "main.h"

/**
 * get_flags - finds active flags
 * @format: Formatted string which contains list of the arguments
 * @i: number of arguments.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* this takes the corresponding value*/
	/* 1 2 4 8 16 */
	int j, cumm;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cumm = *i + 1; format[cumm] != '\0'; cumm++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cumm] == FLAGS_CH[j])
			{
				flags = FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = cumm - 1;
	return (flags);
}
