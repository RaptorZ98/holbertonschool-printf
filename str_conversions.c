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
		buff->arr[buff->pos] = strcopy[n];
		buff->pos += 1;
		check_buff(buff);
		buff->length += 1;
	}
}
