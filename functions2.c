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
	buff->arr[buff->pos + 1] = format[i];
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
		write(1, buff->arr, 1023);
		buff->pos = 0;
	}
}
