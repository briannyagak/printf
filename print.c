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

	va_start(arg, format);
	count = 0;
	while (*format != '\0')
	{
	
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int y = va_arg(arg, int);

				write(1, &y, 1);
				count++;
			}
			if (*format == 's')
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
			write(1, format, 1);
			count++;
		}
		format++;
		va_end(arg);
	}
	return (count);
}
