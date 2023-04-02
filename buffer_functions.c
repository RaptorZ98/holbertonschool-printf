#include "main.h"

/**
 * check_buff - checks if buffer is full
 * @buff: buffer
 */
void check_buff(struct Buff *buff)
{
	if (buff->pos == 1024)
	{
		write(1, buff->arr, 1024);
		buff->pos = 0;
	}
	buff->length += 1;
}

/**
 * add_buff - adds a character to the buff
 * @a: the character to add to the buff
 * @buff: the struct with the buffer
 */
void add_buff(struct Buff *buff, char a)
{
	buff->arr[buff->pos] = a;
	buff->pos += 1;
}
