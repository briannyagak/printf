#include "main.h"
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

int _format(char c, va_list arg);
int _putchar(char c);
int _putstr(char *str);
int _putdigit(int x);
/**
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
		       	write(1, format, 1);
			counter++;
		}
		format++;
		
	}
	va_end(arg);
	return (counter);
}

/**
 * _format - checks the format specifier
 * @c: character to be checked
 * @arg: data variables
 *
 * Return: in nteger
 */

int _format(char c, va_list arg)
{
	int counter;

	counter = 0;

	if (c == 'c')
	{
	counter += _putchar(va_arg(arg, int));
	}
	else if (c == 's')
	{
	counter += _putstr(va_arg(arg, char *));
	}
	else if (c == '%')
	{
		write(1, "%", 1);
	}
	else if (c == 'd' || 'i')
	{
	counter += _putdigit(va_arg(arg, int));
	}
	else
	{
	counter +=write(1, &c, 1);
	}
	return (counter);
}

/**
 * _putchar - prints a character to stdout
 * @c: character to be printed
 *
 * Return: an integer
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a string to stdout
 * @str: string to be printed
 *
 * Return: an integer
 */

int _putstr(char *str)
{
		int counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		_putchar(*str);
		str++;
	}
	return (counter);
}

/**
 * _putdigit - prints a digit to stdout
 * @x: digit to be printed
 *
 * Return: an integer
 */
int _putdigit(int x)
{
	int counter = 0;
	int p = 1;
	int temp;
	int num;

	if (x < 0)
	{
		write(1, "-", 1);
		x = -x;
		counter++;
	}
	temp = x;
	while (temp >= 10)
	{
		p = p * 10;
		temp = temp / 10;
	}
	while (p > 0)
	{
		num = x / p;
		_putchar(('0' + num));
		counter++;
		x = x % p;
		p = p / 10;
	}
	return (counter);
}
