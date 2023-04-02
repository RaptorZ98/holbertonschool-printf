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
			add_buff(buff, format[i]);
			check_buff(buff);
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
		{'b', get_b},
		{'u', get_u},
		{'o', get_o},
		{'x', get_x},
		{'X', get_X},
		{'p', get_p},
		{'S', get_hex},
		{'r', str_rev},
		{'R', rot_print}
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
		for (n = 0; n < 13; n++)
		{
			if (format[i] == pct[n].op)
			{
				pct[n].f(a, buff);
				return (i + 1);
			}
		}
		if (n == 13)
		{
			return (get_param(buff, i, format));
		}
	}
	return (i);
}
