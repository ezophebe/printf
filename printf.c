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
		if (*format == '%')
		{
			++format;
			count += print_format(*format, ap);
		}
	}
	va_end(ap);
	return (count);
}

/**
* print_format - Prints based on format specifiers
* @format_spec: format specifier argument
* @ap: Argument pointer.
*
* Return: 1 on success, 0 otherwise.
*/

int print_format(char format_spec, va_list ap)
{
	int count = 0;

	switch (format_spec)
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
		case 'd':
			count += print_digit((long)(va_arg(ap, int)), 10);
			break;
		case 'x':
			case 'X':
			case 'I':
			case 'i':
			count += print_digit((long)(va_arg(ap, unsigned int)), 16);
			break;
		default:
			_putchar('%');
			count += _putchar(format_spec);
			break;
	}
	return (count);
}
