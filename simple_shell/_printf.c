#include "shell.h"

/**
 * _printf - function that prints a string to the standard output
 *
 * @user_string: pointer to string
 *
 * Return: number of byets
 */

void _printf(const char *user_string)
{
	size_t length = strlen(user_string);

	write(STDOUT_FILENO, user_string, length);
}

/**
 * _putchar - function that print char.
 *
 * @c: pointer to string.
 *
 * Return: number of byets.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _memset - function is used to fill a block of memory with a particular value
 * @ptr: pointer to the block of memory to be filled
 * @val: value to be used to fill the block of memory
 * @num: number of bytes to be filled
 * Return: pointer to the block of memory that was filled
 */

char *_memset(char *ptr, char val, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		ptr[i] = val;
	return (ptr);
}

/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
