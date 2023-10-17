#include "main.h"
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

/*
 * _printf - function that produces output according to a format.
 * @format: character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count;
	va_list arg;

	va_start(arg, f);
	count = 0;
	while (*f != '\0')
	{
		if (f == NULL)
		{
			return (NULL);
		}
		if (*f == '%')
		{
			f++;
			if (*f == 'c')
			{
				int y = va_arg(arg, int);

				write(1, &y, 1);
				count++;
			}
			if (*f == 's')
			{
				char *str = va_arg(arg, char *);

				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
		}
		else
		{
			write(1, f, 1);
			count++;
		}
		f++;
		va_end(arg);
	}
	return (count);
}
