#include "shell.h"

/**
 * _putchar - prints a character
 * @s: character to be printed
 * Return: returns the character
 */
int _putchar(char s)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
	{
		buffer[i++] = s;
	}
	return (1);
}

/**
 * _puts - prints a string
 * @str: string to be printed
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
