#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void get_c(va_list a, struct Buff *buff)
{
	buff.arr[buff.length] = va_arg(a, char);
	buff.length += 1;
}

void get_s(va_list a, struct Buff *buff)
{
	int as;
	char *sa;

	sa = va_arg(a, *char);

	for (as = 0; sa[as] != '\0'; as++)
	{
		 buff.arr[buff.length] = sa[as];

		 buff.length += 1;
	}
}

void get_d(va_list a, struct Buff *buff)
{
	buff.arr[buff.length] = (va_arg(a, int) + '0');
	buff.length += 1;
}
