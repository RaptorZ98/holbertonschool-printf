#include "main.h"
/**
 * get_p - prints an adress
 * @a: the list of original parameters
 * @buff: the struct with the buffer
 */
void get_p(va_list a, struct Buff *buff)
{
	long int i, b, c, p;
	char list[14];

	i = va_arg(a, long int);
	if (i == 0)
	{
		print_nill(buff);
		return;
	}
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
 * @buff: the struct with the buffer
 */
void print_nill(struct Buff *buff)
{
	char nill[5] = {'(', 'n', 'i', 'l', ')'};
	int pos;

	for (pos = 0; pos < 5; pos++)
	{
		buff->arr[buff->pos] = nill[pos];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
}
/**
 *get_hex - hexadecimal
 *@a: the list of parameters
 *@buff: the struct with the buffer
 */
void get_hex(va_list a, struct Buff *buff)
{
	unsigned int num, b;
	char *hex;

	hex = va_arg(a, char *);

	if (hex == NULL)
	{
		hex = "(null)";
		for (hex = 0; hex[num] != '\0'; num++)
		{
			buff->arr[buff->pos] = hex[num];
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
		}
	}
	for (num = 0; hex[num] != '\0'; num++)
		if ((hex[num] > 0 && hex[num] < 32) || hex[num] >= 127)
		{
			b = hex[num];
			print_assi(buff, b);
			make_hex(b, buff);
		}
		else
		{
			buff->arr[buff->pos] = hex[num];
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
		}
}
/**
 * make_hex - hex
 * @a: the list of parameters
 * @buff: the struct with the buffer
 */
void make_hex(int a, struct Buff *buff)
{
	unsigned int i, b, c, p;
	char list[2];

	i = a;
	c = 0;

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
 * print_assi - print assi numbers
 *@b: b
 *@buff: the struct whith the buffer
 */
void print_assi(struct Buff *buff, int b)
{
	int ls = 0;
	char lista[3] = {'\\', 'x', '0'};

	for (; ls < 3; ls++)
	{
		if (ls <= 1 || (ls == 2 && b < 16))
		{
			buff->arr[buff->pos] = lista[ls];
			buff->pos += 1;
			check_buff(buff);
			buff->length += 1;
		}
	}
}
