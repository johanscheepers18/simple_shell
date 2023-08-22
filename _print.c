#include "shell.h"

/**
 * _putchar - prints a character
 * @s: character to be printed
 * Return: returns the character
 */
int _putchar(char s)
{
	return (write(1, &s, 1));
}

/**
 * _puts - prints a string
 * @str: string to be printed
 */
void _puts(char *str)
{
	int x = 0;

	for (; str[x] != '\0'; x++)
	{
		_putchar(str[i]);
	}
}
