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
			buff->arr[buff->length] = format[i];
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
		{'%', get_per}
	};

	i++;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			return (int get_per(struct Buff *buff, int i));
		else
		{
			for (n = 0; n < 5; n++)
			{
				if (format[i] == pct[n].op)
				{
					pct[n].f(a, buff);
					i++;
					return (i);
				}
			}
		}
		if (format[i] == ' ')
			i++;
			return (i);
		if (n == 5)
		{
			buff->arr[buff->length] = '%';
			buff->arr[buff->length + 1] = format[i];
			i++;
			buff->length += 2;
			return (i);
		}
	}
	return (i);
}
