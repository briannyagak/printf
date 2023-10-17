#include "main.h"
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

int _format(char c, va_list arg);
int _putchar(int c);
int _putstr(char *str);

/*
 * _printf - function that produces output according to a format.
 * @format: character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int counter;
	va_list arg;

	va_start(arg, format);
	counter = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			counter += _format(*format, arg);
		}
		else
		{
			write(1, &format, 1);
		}
		format++;
		counter++;
	}
	va_end(arg);
	return (counter);
}

/*
 * _format - checks the format specifier
 * @c: character to be checked
 * @arg: data variables
 *
 * Return: integer
 */

int _format(char c, va_list arg)
{
	int counter;
	counter = 0;

	if (c == 'c')
	{
		counter += _putchar(va_arg(arg, int));
	}
	if (c == 's')
	{
	counter += _putstr(va_arg(arg, char *));
	}
	if (c == '%')
	{
	write(1, &c, 1);
	counter++;
	}
	else
	{
	write(1, &c, 1);
	counter++;
	}
	return (counter);
}

/*
 * _putchar - prints a character to stdout
 * @c: character to be printed
 *
 * return: an integer
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}

/*
 * _putstr - prints a string to stdout
 * @str: string to be printed
 *
 * return: an integer
 */

int _putstr(char *str)
{
	int counter;
	counter = 0;
	while (*str)
	{
		_putchar((int)*str);
		counter++;
		str++;
	}
	return (counter);
}
