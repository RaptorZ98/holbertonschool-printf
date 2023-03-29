#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * get_c - adds a character to the buffer
 * @a: function parameter
 * @buff: buffer
 */

void get_c(va_list a, struct Buff *buff)
{
	buff->arr[buff->length] = va_arg(a, int);
	buff->length += 1;
}
/**
 * get_s - adds a character to the buffer
 * @a: function parameter
 * @buff: buffer
 */
void get_s(va_list a, struct Buff *buff)
{
	int as;
	char *sa;

	sa = va_arg(a, char *);
	if (sa != NULL)
	{
		for (as = 0; sa[as] != '\0'; as++)
		{
			buff->arr[buff->length] = sa[as];
			buff->length += 1;
		}
	}
	else
	{
		sa = "(null)";
		for (as = 0; sa[as] != '\0'; as++)
		{
			buff->arr[buff->length] = sa[as];
			buff->length += 1;
		}
	}
}
/**
 * get_d - adds a character to the buffer
 * @a: function parameter
 * @buff: buffer
 */
void get_d(va_list a, struct Buff *buff)
{
	int i, n, num;

	i = va_arg(a, int);
	n = 1;

	if (i < 0)
	{
		buff->arr[buff->length] = '-';
		buff->length += 1;
		num = i * -1;
	}
	else
		num = i;
	for (; num / n > 9; )
		n *= 10;
	for (; n != 0; )
	{
		buff->arr[buff->length] = ('0' + num / n);
		buff->length += 1;
		num %= n;
		n /= 10;
	}
}
/**
 * get_per - saves the percentage
 * @buff: buffer
 * @i: i
 * Return: i
 */
int get_per(struct Buff *buff, int i)
{
	buff->arr[buff->length] = '%';
	buff->length += 1;
	i++;
	return (i);
}
