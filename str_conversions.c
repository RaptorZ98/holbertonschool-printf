#include "main.h"

/**
 * str_rev - prints reversed string
 * @a: list of parameters
 * @buff: struct with the buff
 */

void str_rev(va_list a, struct Buff *buff)
{
	char *strcopy;
	int i, n;

	strcopy = va_arg(a, char *);
	if (strcopy == NULL)
		strcopy = "(null)";
	i = 0;
	while (strcopy[i] != '\0')
		i++;
	for (n = i - 1; n >= 0; n--)
	{
		add_buff(buff, strcopy[n]);
		check_buff(buff);
	}
}

/**
 * rot_print - prints a string in rot 13 format
 * @a: the parameter list
 * @buff: the struct with the buffer
 */
void rot_print(va_list a, struct Buff *buff)
{
	char *str;
	int pos;

	str = va_arg(a, char *);
	if (str == NULL)
		str = "(null)";
	for (pos = 0; str[pos] != '\0'; pos++)
	{
		if ((str[pos] > 64 && str[pos] < 78) || (str[pos] > 96 && str[pos] < 110))
			str[pos] += 13;
		else if ((str[pos] > 77 && str[pos] < 91) ||
				(str[pos] > 109 && str[pos] < 123))
			str[pos] -= 13;
	}
	for (pos = 0; str[pos] != '\0'; pos++)
	{
		add_buff(buff, str[pos]);
		check_buff(buff);
	}
}
