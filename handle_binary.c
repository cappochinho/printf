#include "main.h"

/**
 * handle_binary - handles binary representation of a number
 * @n: number to be binary-represented
 * @p: number of characters printed
 */

void handle_binary(unsigned int n, unsigned int *p)
{
	if (n > 1)
	{
		*p += 1;
		handle_binary(n >> 1, p);
	}
	_putchar((n & 1) + '0');
}