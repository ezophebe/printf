#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _str_length(char *val);
int _puts(char *s);
int _putchar(char c);
int print_digit(long val, int base_val);
int print_format(char format_spec, va_list ap);

#endif
