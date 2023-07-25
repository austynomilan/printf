#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(int c);
int print_string(char *s);
int print_percent();
int print_binary(unsigned int num);
int print_pointer(void *ptr);

#endif
