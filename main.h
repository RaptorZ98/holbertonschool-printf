#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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


/* Main function */

int _printf(const char *format, ...);

/* Read format */

void read_format(const char *format, va_list a, struct Buff *buff);

int read_porcent(int i, const char *format, struct Buff *buff, va_list a);

/* Percentage behaviour */

int get_per(struct Buff *buff, int i);

int get_white(struct Buff *buff, int i);

int get_param(struct Buff *buff, int i, const char *format);

/* Mandatory functions */

void get_c(va_list a, struct Buff *buff);

void get_s(va_list a, struct Buff *buff);

void get_d(va_list a, struct Buff *buff);

/* Conversions */

void get_u(va_list a, struct Buff *buff);

void get_o(va_list a, struct Buff *buff);

void get_x(va_list a, struct Buff *buff);

void get_X(va_list a, struct Buff *buff);

void get_b(va_list a, struct Buff *buff);

/* Auxiliary functions */

char get_letter(unsigned int n, int i);

void print_nill(struct Buff *buff);

void print_assi(struct Buff *buff, int b);

/* More conversions */

void get_p(va_list a, struct Buff *buff);

void get_hex(va_list a, struct Buff *buff);

void make_hex(int a, struct Buff *buff);

/* Str conversions */

void str_rev(va_list a, struct Buff *buff);

void rot_print(va_list a, struct Buff *buff);

/* Buff checker */

void check_buff(struct Buff *buff);

void add_buff(struct Buff *buff, char a);

#endif
