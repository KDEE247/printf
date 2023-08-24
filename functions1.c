#include "main.h"
/* PRINT UNSIGNED NUMBER */
/**
 * print_unsigned - Prints an unsigned number.
 * @types: list of the arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - prints an unsigned number in the octal notation.
 * @types: list of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: number of chars printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal - prints an unsigned number in the hexadecimal notation.
 * @types: list of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - prints unsigned number in Upper hexadecimal notation.
 * @types: list of arguments.
 * @buffer: buffer Array to handle print.
 * @flags: calculates active flags.
 * @width: get Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXA NUM IN LOWER OR UPPER */
/**
 * print_hexa - prints a hexadecimal number in lower or upper.
 * @types: list of arguments.
 * @map_to: array of values to map the number.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @flag_ch: calculates active flags.
 * @width: get Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * @size: Size specification.
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
