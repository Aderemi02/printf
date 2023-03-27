#include "main.h"
/**
 * writep_pointer - Writes memory address
 * @buffer: chars array
 * @ind: Index at which the number starts
 * Return: chars length
 */
int writep_pointer(char buffer[], int ind)
{
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
