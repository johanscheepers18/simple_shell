#include "shell.h"

/**
 * env - this function is used to get the environment
 * @a: the global variables to be used
 * @b: the directory
 * Return: return the path, or NULL if fail
 */
char *env(char **a, char *b)
{
	int x = 0, y = 0;
	char *i, *j;

	for (; a[x] ; x++)
	{
		i = malloc(1024);

		for (; a[x][y] != '='; y++)
		{
			i[y] = a[x][y];
		}

		if (comp(i, b))
		{
			j = eq_check(a[x]);
			free(i);
			return (j);
		}

		free(i);
	}

	return (NULL);
}

/**
 * _path - is used to join all arguments
 * @a: start string
 * @b: string to be added
 * Return: returns the c on success else returns NULL
 */
char *_path(char **a, char **b)
{
	struct stat status;

	int x = 0, y = 0, z;
	char *c, **d;

	for (; b[x] ; x++)
	{
		c = malloc(60);
		cat_str(c, b[x]);
		cat_str(c, "/");
		cat_str(c, a[0]);

		if (stat(c, &status) == 0)
		{
			for (; *a[y] != '\0' ; y++)
			{
				;
			}

			d = malloc(sizeof(char *) * (y + 1));
			d[y] = NULL;
			d[0] = _duplicate_str(c);

			for (z = 1 ; a[z] ; z++)
			{
				d[z] = _duplicate_str(a[z]);
			}

			exec(d);
			return (c);
		}
		free(c);
	}
	return (NULL);
}

/**
 * path_finder - finds a certain path
 * @a: path should be found for these arguments
 * Return: returns the path
 */
char **path_finder(char **a)
{
	char *path, **x, *y;

	y = ":";

	path = env(a, "PATH");
	x = split(path, y);
	return (x);
}
