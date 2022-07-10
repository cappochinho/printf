#include "main.h"

/**
 * _printf - prints any number of argument passed to it
 * @format: format specifier
 *
 * Return: Number of arguments printed
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
		return (0);

	va_list ap;
	va_start(ap, format);

	char l, *s;
	int i, n, nprinted, found, there;
	i = n = nprinted = found = there = 0;
	int len = strlen(format);

	while (format[i])
	{
		found = 0;
		if ((format[i] == '%') && ((i + 1) < len))
		{
			there = 1;
			switch (format[i + 1])
			{
			case 'c' :
				l = (char) va_arg(ap, int);
				write(1, &l, 1);
				nprinted++;
				break;

			case 's':
				s = va_arg(ap, char *);
				if (s != NULL)
				{
					for (int j = 0; s[j] != '\0'; j++)
					{
						write(1, &s[j], 1);
						nprinted++;
					}
				}
				break;

			case '%':
				l = '%';
				write(1, &l, 1);
				nprinted++;
				break;
			}

			if (there != 0)
			{
				i += 2;
				continue;
			}
		}
		write(1, &format[i], 1);
		nprinted++;
		i++;
	}

	va_end(ap);
	return (nprinted);
}