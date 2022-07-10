#include "main.h"

/**
 * handle_unsignedToBinary - handles an integer.
 * @arg: argument
 * Return: 0
 */
int handle_unsignedToBinary(va_list arg)
{

    unsigned int n = va_arg(arg, unsigned int);
    unsigned int handled;

    handle_binary(n, &handled);
    handle_binary(n, &handled);

    return (handled);
}

/**
 * handle_oct - handles number in octxl base.
 * @arg: list containing octxl number to be handled
 * Return: number of octxls handled
 */

int handle_oct(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    unsigned int copy;
    char *octx;
    int i, j, charhandled = 0;

    if (num == 0)
        return (_putchar('0'));
    for (copy = num; copy != 0; j++)
    {
        copy = copy / 8;
    }
    octx = malloc(j);
    if (!octx)
        return (-1);

    for (i = j - 1; i >= 0; i--)
    {
        octx[i] = num % 8 + '0';
        num = num / 8;
    }

    for (i = 0; i < j && octx[i] == '0'; i++)
        ;
    for (; i < j; i++)
    {
        _putchar(octx[i]);
        charhandled++;
    }
    free(octx);
    return (charhandled);
}

/**
 * handle_unsignedIntToHex - handles unsigned int to hexadecimal.
 * @num: number to handle
 * @_case: letter `a` on the case to handle it (upper or lower)
 * Return: number or char handled
 */
int handle_unsignedIntToHex(unsigned int num, char _case)
{
    unsigned int num2;
    int i, j, remainder, nbrCharacters = 0;
    char *numhex;

    for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
        ;

    numhex = malloc(nbrCharacters);
    for (i = 0; num != 0; i++)
    {
        remainder = num % 16;
        if (remainder < 10)
            numhex[i] = remainder + '0';
        else
            numhex[i] = remainder - 10 + _case;
        num = num / 16;
    }
    for (j = i - 1; j >= 0; j--)
        _putchar(numhex[j]);
    free(numhex);
    return (nbrCharacters);
}