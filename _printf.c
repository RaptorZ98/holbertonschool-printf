#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _print - prints
 * @format: the things to print
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int n, i;
	lists pct[] = {
		{'c', get_c},
		{'s', get_s},
		{'d', get_d},
		{'i', get_d}
	};
	Buff buff;
	va_list pf;

	buff.length = 0;
	if (format == NULL)
		return (0);
	va_start(pf, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				buff.arr[buff.length] = format[i];
				buff.length += 1;
			}
			for (n = 0; n < 4; n++)
			{
				if (format[i] == pct[n].op)
				{
					pct[n].f(pf, &buff);
					i++;
					break;
				}
			}
		}
		else if (format[i] == '\\')
		{
			i++;
			if (format[i] == '\n')
			{
				buff.arr[buff.length] = format[i];
				buff.length += 1;
			}
			else if (format[i] == '\\')
			{
				buff.arr[buff.length] = format[i];
				buff.length += 1;
			}
		}
		else
		{
			buff.arr[buff.length] = format[i];
			buff.length += 1;
			i++;
		}
	}
	write(1, buff.arr, buff.length);
	return (buff.length);
}
