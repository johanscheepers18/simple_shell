#include "shell.h"

/**
 * main - Entry point
 * @x: amount of arguments
 * @y: array of arguments
 * @z: global variables to be used
 * Return: returns 0
 */
int main(int x, char **y, char **z)
{
	char *command, *a = NULL, *de = "\t \a\n", **b;

	(void)x;

	b = path_finder(z);

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		a = _rl();
		y = split(a, de);
		command = _path(y, b);

		if (command == NULL)
		{
			exec(y);
		}

		free(a);
		free(y);
		free(command);
	}

	return (0);
}
