#ifndef MAIN_H
#define MAIN_H

/**
 * struct Buff - A struct for the buffer and its used length
 * @length: used length of the buffer
 * @buff: the buffer
 */
typedef struct Buff
{
	int length; 
	char arr[1024];
} Buff;

/**
 * struct les - a struct for the functions to use in each case
 * @op: the char to detect
 * @f: the function to use if op detected
 */
typedef struct les
{
	char op;
	void (*f)(va_list a, struct Buff *buff);
} lists;

int _print(const char *format, ...);

void get_c(va_list a, struct Buff *buff);
void get_s(va_list a, struct Buff *buff);
void get_d(va_list a, struct Buff *buff);

#endif
