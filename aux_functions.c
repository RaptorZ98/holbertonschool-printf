#include "main.h"


/**
 * get_letter - gets the correct letter
 * @n: unsigned int passed to check
 * @i: fucntion that called
 * Return: the correct letter
 */

char get_letter(unsigned int n, int i)
{
	unsigned int u;
	int p;
	char mayus[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char lower[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	p = 0;
	for (u = 10; u < 16; u++)
	{
		if (n == u)
		{
			if (i == 2)
				return (mayus[p]);
			else
				return (lower[p]);
		}
		p++;
	}
	return ('o');
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
		add_buff(buff, nill[pos]);
		check_buff(buff);
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
			add_buff(buff, lista[ls]);
			check_buff(buff);
		}
	}
}
