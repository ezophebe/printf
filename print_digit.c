#include "main.h"
/**
  * print_digit - Prints int and hex values.
  * @val: Initial value.
  * @base_val: 2 parameter.
  *
  * Return: A number greater 0 on success.
*/
int print_digit(long val, int base_val)
{
	int count;
	char *hex_symbols;

	hex_symbols = "0123456789abcdef";
	if (val < 0)
	{
		write(1, "-", 1);
		return (print_digit(-val, base_val) + 1);
	}
	else if (val < base_val)
	{
		return (_putchar(hex_symbols[val]));
	}
	else
	{
		count = print_digit(val / base_val, base_val);
		return (count + print_digit(val % base_val, base_val));
	}
}
