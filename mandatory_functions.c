#include "main.h"

/**
 * get_c - adds a character to the buffer
 * @a: function parameter
 * @buff: buffer
 */

void get_c(va_list a, struct Buff *buff)
{
	add_buff(buff, va_arg(a, int));
	check_buff(buff);
}


/**
 * get_s - adds a string to the buffer
 * @a: function parameter
 * @buff: buffer
 */

void get_s(va_list a, struct Buff *buff)
{
	int pos;
	char *str;

	str = va_arg(a, char *);
	if (str == NULL)
		str = "(null)";
	for (pos = 0; str[pos] != '\0'; pos++)
	{
		add_buff(buff, str[pos]);
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
	int num, cnum, k, len = 0, pos, chaint;
	char intstr[11];

	num = va_arg(a, int);
	cnum = num;
	if (num == 0)
	{
		add_buff(buff, '0');
		check_buff(buff);
	}
	if (num < 0)
	{
		add_buff(buff, '-');
		check_buff(buff);
	}
	while (cnum != 0)
	{
		cnum /= 10;
		len++;
	}
	pos = len - 1;
	cnum = num;
	while (cnum != 0)
	{
		if (cnum > 0)
			chaint = cnum % 10;
		else
			chaint = (cnum % 10) * -1;
		intstr[pos] = chaint + '0';
		cnum /= 10;
		pos--;
	}
	for (k = 0; k < len; k++)
	{
		add_buff(buff, intstr[k]);
		check_buff(buff);
	}
}
