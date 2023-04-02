#include "main.h"

/**
 * get_per - saves the percentage
 * @buff: buffer
 * @i: i
 * Return: i
 */

int get_per(struct Buff *buff, int i)
{
	add_buff(buff, '%');
	check_buff(buff);
	return (i + 1);
}


/**
 * get_white - prints whitespace
 * @buff: buffer
 * @i: int
 * Return: int i
 */

int get_white(struct Buff *buff, int i)
{
	add_buff(buff, ' ');
	check_buff(buff);
	return (i + 1);
}


/**
 * get_param - prints % and char
 * @buff: buffer
 * @i: int
 * @format: format
 * Return: int i
 */

int get_param(struct Buff *buff, int i, const char *format)
{
	add_buff(buff, '%');
	check_buff(buff);
	add_buff(buff, format[i]);
	check_buff(buff);
	return (i + 1);
}
