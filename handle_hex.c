#include "main.h"

/**
 * handle_hex_base - base function for handling hexadecimal numbers
 * @arg: argument list containing hexadecimal
 * @_case: a  in caps on lower, handleing the hex number in caps in lower
 * Return: number of digits handled
 */

int handle_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = handle_unsignedIntToHex(num, _case);

	return (nbrCharacters);
}
/**
 * handle_hex - handles a hexadecimal in lower case
 * @arg: list that contains hexadecimal to handle
 * Return: number of digits handled
 */

int handle_hex(va_list arg)
{
	return (handle_hex_base(arg, 'a'));
}

/**
 * handle_HEX - handles a hexadecimal in upper case
 * @arg: list that contains hexadecimal to handle
 * Return: number of digits handled
 */

int handle_HEX(va_list arg)
{
	return (handle_hex_base(arg, 'A'));
}