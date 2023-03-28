#include "main.h"

/**
 * read_format - reads format and passes it to the buffer
 * @format: the format to read
 * @a: the list of parameters of _printf
 * @buff: the buffer
 */

void read_format(const char *format, va_list a, struct Buff *buff)
{
	int i, n;
	lists pct[] = {
		{'c', get_c},
		{'s', get_s},
		{'d', get_d},
		{'i', get_d}
	};

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				buff->arr[buff->length] = format[i];
				buff.length += 1;
			}
			for (n = 0; n < 4; n++)
			{
				if (format[i] == pct[n].op)
				{
					pct[n]->f(a, buff);
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
				buff->arr[buff->length] = format[i];
				buff->length += 1;
			}
			else if (format[i] == ' ')
			{
				buff->arr[buff->length] = format[i];
				buff->length += 1;
			}
		}
		else
		{
			buff->arr[buff->length] = format[i];
			buff->length += 1;
			i++;
		}
	}
}
