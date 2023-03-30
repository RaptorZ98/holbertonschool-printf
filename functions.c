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
	buff->arr[buff->pos] = va_arg(a, int);
	buff->pos += 1;
	check_buff(buff);
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
			buff->arr[buff->pos] = sa[as];
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
		}
	}
	else
	{
		sa = "(null)";
		for (as = 0; sa[as] != '\0'; as++)
		{
			buff->arr[buff->pos] = sa[as];
			buff->pos += 1;
			check_buff(buff);
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
	int i, n;

	i = va_arg(a, int);
	n = 1;
	if (i == 0)
	{
		buff->arr[buff->pos] = ('0' + 0);
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	else if (i < 0)
	{
		buff->arr[buff->pos] = '-';
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
		get_dmin(buff, i);
	}
	else
	{
		for (; i / n > 9; )
			n *= 10;
		for (; n != 0; )
		{
			buff->arr[buff->pos] = ('0' + i / n);
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
			i %= n;
			n /= 10;
		}
	}
}
/**
 * get_dmin - prints minus int
 * @buff: buffer
 * @i: integer
 */
void get_dmin(struct Buff *buff, int i)
{
	int n, j, t, k, len;
	char s[11];

	n = i;
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	n = i;
	j = len - 1;
	while (n != 0)
	{
		t = (n % 10) * -1;
		s[j] = t + '0';
		n /= 10;
		j--;
	}
	for (k = 0; k < len; k++)
	{
		buff->arr[buff->pos] = s[k];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
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
	buff->arr[buff->pos] = '%';
	buff->pos += 1;
	check_buff(buff);
	buff->length += 1;
	i++;
	return (i);
}
