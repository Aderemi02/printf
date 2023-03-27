#include "main.h"

/**
 * printp_pointer - prints a pointer
 * @types: types of args
 * @buffer: buffer array
 * Return: pointer to number of chars
 */

int printp_pointer(va_list types, char buffer[])
{
	int index = BUFF_SIZE - 2, len = 2;
	char map_to[] = "0123456789abcdef";
	unsigned long num_adrs;
	void *adrs = va_arg(types, void *);

	if (adrs == NULL)
		return (write(1, "(nul)", 5));

	buffer[BUFF_SIZE - 1] = '\0';

	num_adrs = (unsigned long)adrs;

	while (num_adrs > 0)
	{
		buffer[index--] = map_to[num_adrs % 16];
		num_adrs /= 16;
		len++;
	}
	index++;

	return (writep_pointer(buffer, index));
}
