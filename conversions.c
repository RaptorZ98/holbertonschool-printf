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
		add_buff(buff, '0');
		check_buff(buff);
		return;
	}
	while (i / n > 9)
		n *= 10;
	while (n != 0)
	{
		add_buff(buff, ('0' + i / n));
		check_buff(buff);
		i %= n;
		n /= 10;
	}
}


/**
 * get_o - transforms unsigned int to octal
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
		add_buff(buff, '0');
		check_buff(buff);
	}
	while (i > 0)
	{
		list[c] = (i % 8) + '0';
		i /= 8;
		c++;
	}
	for (b = 0; b < c; b++)
	{
		add_buff(buff, list[c - b - 1]);
		check_buff(buff);
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
		add_buff(buff, '0');
		check_buff(buff);
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
		add_buff(buff, list[c - b - 1]);
		check_buff(buff);
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
		add_buff(buff, '0');
		check_buff(buff);
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
		add_buff(buff, list[c - b - 1]);
		check_buff(buff);
	}
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

