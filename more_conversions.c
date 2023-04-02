#include "main.h"



/**
 * get_p - prints an adress
 * @a: the list of original parameters
 * @buff: the struct with the buffer
 */

void get_p(va_list a, struct Buff *buff)
{
	unsigned long int i, b, c, p;
	char list[100];

	i = va_arg(a, long int);
	if (i == 0)
	{
		print_nill(buff);
		return;
	}
	c = 0;
	add_buff(buff, '0');
	check_buff(buff);
	add_buff(buff, 'x');
	check_buff(buff);

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
			add_buff(buff, hex[num]);
			check_buff(buff);
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
			add_buff(buff, hex[num]);
			check_buff(buff);
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
		add_buff(buff, list[c - b - 1]);
		check_buff(buff);
	}
}
