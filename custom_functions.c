#include "main.h"
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
