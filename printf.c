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
	const char *str;
	char character, *char_str;
	int count, int_val, string_lt;
	double double_val;


	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	for  (str = format; *str != '\0'; ++str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			count++;
		}
		if (*str == '\0')
			break;
		switch (*str)
		{
			case '%':
			switch (*++str)
			{
			case 'c':
				character = va_arg(ap, int);
				write(1, &character, 1);
				count++;
				break;
			case 's':
				char_str = va_arg(ap, char *);
				string_lt = _str_length(char_str);
				write(1, char_str, string_lt);
				count += string_lt;
				break;
			case '%':
				write(1, str, 1);
				count++;
				break;
			}
		}
	}
	va_end(ap);
	return (count);
}
