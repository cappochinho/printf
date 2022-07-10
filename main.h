#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
void handle_binary(unsigned int n, unsigned int *p);
int handle_char(va_list arg);
int handle_int(va_list arg);
int handle_STR(va_list arg);
int handle_str(va_list arg);
int handle_unsigned(va_list arg);
int handle_unsignedToBinary(va_list arg);
int handle_oct(va_list arg);
int handle_unsignedIntToHex(unsigned int num, char _case);
int handle_hex_base(va_list arg, char _case);
int handle_hex(va_list arg);
int handle_HEX(va_list arg);

/**
 * struct identifierStruct - structure definition of a printTypeStruct
 * @indentifier: type
 * @printer: function to print
 */
typedef struct identifierStruct
{
    char *indentifier;
    int (*printer)(va_list);
} identifierStruct;

#endif