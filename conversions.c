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
		buff->arr[buff->pos] = '0';
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
		return;
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
	unsigned int i, b, c, p;
	char list[8];

	i = va_arg(a, int);
	c = 0;
	if (i == 0)
	{
		buff->arr[buff->pos] = 0 + '0';
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	while (i > 0)
	{
		p = i % 16;
		if (p > 9)
		{
			list[c] = get_letter(p, 1);
			c++;
		}
		else
		{
			list[c] = p + '0';
			c++;
		}
		i /= 16;
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
 * get_X - convert unsigned int into hexa
 * @a: the list of parameters
 * @buff: the struct with the buffer
 */
void get_X(va_list a, struct Buff *buff)
{
	unsigned int i, b, c, p;
	char list[8];

	i = va_arg(a, int);
	c = 0;
	if (i == 0)
	{
		buff->arr[buff->pos] = 0 + '0';
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
	while (i > 0)
	{
		p = i % 16;
		if (p > 9)
		{
			list[c] = get_letter(p, 2);
			c++;
		}
		else
		{
			list[c] = p + '0';
			c++;
		}
		i /= 16;
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
 * get_letter - gets the correct letter
 * @n: unsigned int passed to check
 * @i: fucntion that called
 * Return: the correct letter
 */
char get_letter(unsigned int n, int i)
{
	unsigned int u;
	int p;
	char mayus[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char lower[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	p = 0;
	for (u = 10; u < 16; u++)
	{
		if (n == u)
		{
			if (i == 2)
				return (mayus[p]);
			else
				return (lower[p]);
		}
		p++;
	}
	return('o');
}
