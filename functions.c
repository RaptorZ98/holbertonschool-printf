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
}
/**
 * get_d - adds a character to the buffer
 * @a: function parameter
 * @buff: buffer
 */
void get_d(va_list a, struct Buff *buff)
{
	buff->arr[buff->length] = (va_arg(a, int) + '0');
	buff->length += 1;
}
