#include "main.h"

/**
 * get_u - prints unsigned int
 * @a: the va list
 * @buff: the struct with the buffer
 */
void get_u(va_list a, struct Buff *buff)
{
	unsigned int i, n;

	i = va_arg(a, int);
	n = 1;
	if (i == 0)
	{
		buff->arr[buff->pos] = ('0' + 0);
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	while (i / n > 9)
		n *= 10;
	while (n != 0)
	{
		buff->arr[buff->pos] = ('0' + i / n);
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
		i %= n;
		n /= 10;
	}
}
/**
 * get_o - transforms unsigned int to
 * @a: the list of parameters
 * @buff: the struct with the buffer
 */
void get_o(va_list a, struct Buff *buff)
{
	unsigned int i, b, c;
	char list[11];

	i = va_arg(a, int);
	c = 0;
	if (i == 0)
	{
		buff->arr[buff->pos] = ('0' + 0);
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	while (i > 0)
	{
		list[c] = (i % 8) + '0';
		i /= 8;
		c++;
	}
	for (b = 0; b < c; b++)
	{
		buff->arr[buff->pos] = list[c - b - 1];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
}
/**
 * get_x - convert unsigned int into hexa
 * @a: the list of parameters
 * @buff: the struct with the buffer
 */
void get_x(va_list a, struct Buff *buff)
{

}
/**
 * get_X - convert unsigned int into hexa
 * @a: the list of parameters
 * @buff: the struct with the buffer
 */
void get_X(va_list a, struct Buff *buff)
{

}
