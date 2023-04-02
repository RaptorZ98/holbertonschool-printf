#include "main.h"

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
	buff.pos = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(pf, format);
	read_format(format, pf, &buff);
	write(1, buff.arr, buff.pos);
	va_end(pf);
	return (buff.length);
}
