#include "shell.h"

/**
 * str_length - gets the length of a string
 * @str: string to be used
 * Return: returns 0 if string is empty, else returns the length of the string
 */
unsigned int str_length(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}

	return ((1) + str_length(str + 1));
}

/**
 * _rl - this function is used to read the command line
 * Return: returns the line
 */
char *_rl(void)
{
	int x = 0;
	size_t y = 0;
	char *z = NULL;

	if (getline(&z, &y, stdin) == -1)
	{
		free(z);
		exit(-1);
	}

	x = str_length(z);
	z[x - 1] = '\0';

	return (z);
}

/**
 * cat_str - is used to join two string together
 * @dest: the destination of the string of the combined strings
 * @src: the second string to be added to dest
 * Return: returns the combined strings
 */
char *cat_str(char *dest, char *src)
{
	int x = 0, y = 0;

	for (; dest[x] != '\0'; x++)
	{
		;
	}

	for (; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
	}

	dest[x] = '\0';

	return (dest);
}

/**
 * _duplicate_str - is used to duplicate a string
 * @str: the string that should be duplicated
 * Return: returns NULL or the duplicated string
 */
char *_duplicate_str(char *str)
{
	int x = 0;
	char *y;

	if (str == NULL)
	{
		return (NULL);
	}

	y = malloc(str_length(str) + 1);

	if (y == NULL)
	{
		return (NULL);
	}

	while (str[x] != '\0')
	{
		y[x] = str[x];
		x++;
	}

	y[x] = '\0';

	return (y);
}
