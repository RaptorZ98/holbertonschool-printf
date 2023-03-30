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
	buff->arr[buff->pos] = ' ';
	buff->pos += 1;
	check_buff(buff);
	buff->length += 1;
	i++;
	return (i);
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
	buff->arr[buff->pos] = '%';
	buff->pos += 1;
	check_buff(buff);
	buff->arr[buff->pos] = format[i];
	buff->pos += 1;
	check_buff(buff);
	i++;
	buff->length += 2;
	return (i);
}

/**
 * check_buff - checks if buffer is full
 * @buff: buffer
 */
void check_buff(struct Buff *buff)
{
	if (buff->pos == 1024)
	{
		write(1, buff->arr, 1024);
		buff->pos = 0;
	}
}

/**
 *
 *
 *
 */
void get_b(va_list a, struct Buff *buff)
{
	unsigned int l = 0, b = 0, c = 0;
	char as[32];

	l = va_arg(a, int);

	if (l == 0)
	{
		buff->arr[buff->pos] = 0;
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	while (l > 0)
	{
		as[c] = (l % 2) + '0';
		l = l / 2;
		c++;
	}
	for (b = 0; b < c; b++)
	{
		buff->arr[buff->pos] = as[c - b - 1];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
}
