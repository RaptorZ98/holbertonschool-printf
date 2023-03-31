#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct Buff - A struct for the buffer and its used length
 * @length: used length of the buffer
 * @pos: the position of the buffer
 * @arr: the buffer
 */
typedef struct Buff
{
	int length;
	int pos;
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

int _printf(const char *format, ...);
int read_porcent(int i, const char *format, struct Buff *buff, va_list a);
void read_format(const char *format, va_list a, struct Buff *buff);
void get_num(int n, struct Buff *buff, int len);
void check_buff(struct Buff *buff);

int get_white(struct Buff *buff, int i);
int get_per(struct Buff *buff, int i);
int get_param(struct Buff *buff, int i, const char *format);
void get_b(va_list a, struct Buff *buff);

void get_dmin(struct Buff *buff, int i);
void get_c(va_list a, struct Buff *buff);
void get_s(va_list a, struct Buff *buff);
void get_d(va_list a, struct Buff *buff);

void get_u(va_list a, struct Buff *buff);
void get_o(va_list a, struct Buff *buff);
void get_x(va_list a, struct Buff *buff);
void get_X(va_list a, struct Buff *buff);

char get_letter(unsigned int n, int i);
#endif
