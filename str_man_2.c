#include "shell.h"

/**
 * eq_check - is used to check for the quals sign
 * @str: the string that should be checked
 * Return: returns the location of the equals
 */
char *eq_check(char *str)
{
	int x = 0;

	for (; str[x] != '=' ; x++)
	{
		;
	}

	return (str + x + 1);
}

/**
 * comp - compares two strings
 * @a: first string
 * @b: second string
 * Return: returns 1 on success else returns 0
 */
int *comp(char *a, char *b)
{
	int x = 0;

	for (; b[x] != '\0' ; x++)
	{
		if (b[x] != a[x])
		{
			return (0);
		}
	}

	return (1);
}
