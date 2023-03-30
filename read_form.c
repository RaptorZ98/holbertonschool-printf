#include "main.h"

/**
 * read_format - reads format and passes it to the buffer
 * @format: the format to read
 * @a: the list of parameters of _printf
 * @buff: the buffer
 */

void read_format(const char *format, va_list a, struct Buff *buff)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = read_porcent(i, format, buff, a);
		}
		else
		{
			buff->arr[buff->pos] = format[i];
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
			i++;
		}
	}
}

/**
 * read_porcent - looks for the correct function
 * @i: int to look in format
 * @format: string given
 * @buff: buffer
 * @a: va list
 * Return: int i
 */
int read_porcent(int i, const char *format, struct Buff *buff, va_list a)
{
	int n;
	lists pct[] = {
		{'c', get_c},
		{'s', get_s},
		{'d', get_d},
		{'i', get_d},
		{'b', get_b}
	};

	i++;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			return (get_per(buff, i));
		if (format[i] == ' ')
		{
			return (get_white(buff, i));
		}
		for (n = 0; n < 5; n++)
		{
			if (format[i] == pct[n].op)
			{
				pct[n].f(a, buff);
				i++;
				return (i);
			}
		}
		if (n == 5)
		{
			return (get_param(buff, i, format));
		}
	}
	return (i);
}
