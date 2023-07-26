#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(int c);
int print_string(char *s);
int print_percent(void);
int print_binary(int num);
int print_pointer(void *ptr);
int print_integer(int num);
int print_unsigned_int(unsigned int n, int base, int lowercase, int width);
void handle_flags(int plus_flag, int space_flag, int hash_flag, char specifier);
int print_custom_string(char *s);
const char *print_field_width(const char *format, va_list args);
const char *print_flag_zero(const char *format, va_list args);
void print_reversed_string(char *s);

#endif
