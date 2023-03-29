#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - prints
 * @format: the things to print
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	Buff buff;
	va_list pf;

	buff.length = 0;
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (0);
	va_start(pf, format);
	read_format(format, pf, &buff);
	write(1, buff.arr, buff.length);
	va_end(pf);
	return (buff.length);
}
