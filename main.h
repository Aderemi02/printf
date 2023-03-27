#ifndef MAIN_H
#define MAIN_H

/*****STANDARD LIBRARIES****/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**** PROTOTYPES OF FUNCTIONS USED***/

int _printf(const char *format, ...);

void print_buffer(char buffer[], int *buff_ind);

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_precision(const char *format, int *i, va_list list);

int get_width(const char *format, int *i, va_list list);

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char c);

int append_hexa_code(char ascii_code, char buffer[], int i);

int is_digit(char);

long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char pad, char extra_c);

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size);

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char extra_c, int padd_start);

/**FUNCTION FOR FLAG**/
int get_flags(const char *format, int *i);

/**FUNCTION FOR SIZE**/
int get_size(const char *format, int *i);

/****MACROS***/

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/****STRUCTURE AND TYPEDEF***/

/**
 * struct fmt - Struct operator
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

#endif
