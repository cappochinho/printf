#include "main.h"

/**
 * handle_char - writes the character c to stdout
 * @arg: argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int handle_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * handle_int - handles an integer.
 * @arg: argument
 * Return: 0
 */

int handle_int(va_list arg)
{

	unsigned int divisor = 1, i, resp, charhandled = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		charhandled++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10, charhandled++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (charhandled);
}

/**
 * handle_STR - handles a string with a `S` (upper case) specificer
 * @arg: argument
 * Return: number of character handleed
 */

int handle_STR(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');

			handle_unsignedIntToHex(str[i], 'A');
		}
		else
			_putchar(str[i]);
	}

	return (i);
}

/**
 * handle_str - handles a string with a `s` (lower case) specifier
 * @arg: argument
 * Return: number of character handleed
 */

int handle_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * handle_unsigned - handles an unsigned int.
 * @arg: argument
 * Return: 0
 */

int handle_unsigned(va_list arg)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(arg, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (i + 1);
}