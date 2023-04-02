#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * get_white - prints whitespace
 * @buff: buffer
 * @i: int
 * Return: int i
 */

int get_white(struct Buff *buff, int i)
{
	add_buff(buff, ' ');
	check_buff(buff);
	return (i + 1);
}

/**
 * get_param - prints % and char
 * @buff: buffer
 * @i: int
 * @format: format
 * Return: int i
 */
int get_param(struct Buff *buff, int i, const char *format)
{
	add_buff(buff, '%');
	check_buff(buff);
	add_buff(buff, format[i]);
	check_buff(buff);
	return (i + 1);
}


/**
 *get_b - transforms an unsigned int to binary
 *@buff: buffer
 *@a: function parameter
 */
void get_b(va_list a, struct Buff *buff)
{
	unsigned int l = 0, b = 0, c = 0;
	char as[32];

	l = va_arg(a, int);

	if (l == 0)
	{
		add_buff(buff, '0');
		check_buff(buff);
	}
	while (l > 0)
	{
		as[c] = (l % 2) + '0';
		l = l / 2;
		c++;
	}
	for (b = 0; b < c; b++)
	{
		add_buff(buff, as[c - b - 1]);
		check_buff(buff);
	}
}
