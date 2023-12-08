#include "main.h"
/**
  * _printf - Prints formated input to standard output.
  * @format: Character string argument.
  *
  * Return: Number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	for  (; *format != '\0'; ++format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		switch (*format)
		{
			case '%':
			switch (*++format)
			{
			case 'c':
				count += _putchar(va_arg(ap, int));
				break;
			case 's':
				count += _puts(va_arg(ap, char *));
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				_putchar('%');
				count += _putchar(*format);
				break;
			}
		}
	}
	va_end(ap);
	return (count);
}
/**
 * _str_length - funtion counts len of string
 * @val: given data
 * Return: lenght of string
 */

int _str_length(char *val)
{
	int count = 0;

	while (val[count] != '\0')
		count++;
	return (count);
}

/**
 * _putchar - Prints characters to stdout.
 * @c: Charater to print.
 * Return: 1 on success.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_puts - Prints a string.
 *@s: String parameter.
 *Return: A positive integer on success.
 */

int _puts(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length += _putchar(*s);
			++s;
	}
	return (length);
}
