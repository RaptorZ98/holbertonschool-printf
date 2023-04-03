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
	int pos;
	char *str;

	str = va_arg(a, char *);
	if (str == NULL)
		str = "(null)";
	for (pos = 0; str[pos] != '\0'; pos++)
	{
		if ((str[pos] >= 'A' && str[pos] <= 'M') ||
				(str[pos] >= 'a' && str[pos] <= 'm'))
		{
			add_buff(buff, str[pos] + 13);
			check_buff(buff);
		}
		else if ((str[pos] >= 'N' && str[pos] <= 'Z') ||
				(str[pos] >= 'n' && str[pos] <= 'z'))
		{
			add_buff(buff, str[pos] - 13);
			check_buff(buff);
		}
		else
		{
			add_buff(buff, str[pos]);
			check_buff(buff);
		}
	}
}
