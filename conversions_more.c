#include "main.h"
/**
 * get_p - prints an adress
 * @a: the list of original parameters
 * @buff: the struct with the buffer
 */
void get_p(va_list a, struct Buff *buff)
{
	long int i, b, c, p;
	char list[12];

	i = va_arg(a, long int);
	c = 0;
	buff->arr[buff->pos] = '0';
	buff->pos += 1;
	check_buff(buff);
	buff->arr[buff->pos] = 'x';
	buff->pos += 1;
	check_buff(buff);
	buff->length += 2;
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
 * print_nill - prints nill
 */
void print_nill(struct Buff *buff)
{
	char nill[6] = {'(', 'n', 'i', 'l', 'l', ')'};
	int pos;

	for (pos = 0; pos < 6; pos++)
	{
		buff->arr[buff->pos] = nill[pos];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
}
