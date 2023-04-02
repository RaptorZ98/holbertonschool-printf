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
	add_buff(va_arg(a, int));
	check_buff(buff);
}

/**
 * get_s - adds a string to the buffer
 * @a: function parameter
 * @buff: buffer
 */
void get_s(va_list a, struct Buff *buff)
{
	int as;
	char *sa;

	sa = va_arg(a, char *);
	if (sa == NULL)
		sa = "(null)";
	for (as = 0; sa[as] != '\0'; as++)
	{
		add_buff(sa[as]);
		check_buff(buff);
	}
}

/**
 * get_d - adds an integer to the buffer
 * @a: function parameter
 * @buff: buffer
 */
void get_d(va_list a, struct Buff *buff)
{
	int i, n, k, len = 0, pos, chaint;
	char intstr[11];

	i = va_arg(a, int);
	n = i;
	if (i == 0)
	{
		add_buff('0');
		check_buff(buff);
	}
	if (i < 0)
	{
		add_buff('-');
		check_buff(buff);
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	pos = len - 1;
	n = i;
	while (n != 0)
	{
		if (n > 0)
			chaint = n % 10;
		else
			chaint = (n % 10) * -1;
		intstr[pos] = chaint + '0';
		n /= 10;
		pos--;
	}
	for (k = 0; k < len; k++)
	{
		add_buff(intstr[k]);
		check_buff(buff);
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
