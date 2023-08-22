#include "shell.c"

/**
 * exec - execute the commands
 * @a: array of pointer to the commands
 * Return: returns 0
 */
int exec(char **a)
{
	pid_t i;
	int x;

	i = fork();

	if (i == 0)
	{
		if (execve(a[0], a, NULL) == -1)
		{
			perror(a[0]);
			exit(1);
		}
	}

	else if (i >= 1)
	{
		wait(&x);
	}

	else
	{
		perror("Error:");
	}

	return (0);
}

/**
 * mem_alloc - realloactes the memory
 * @p: pointer to be used
 * @x: previous buff_size of the memory
 * @y: new Buff_size of the memory
 * Return: returns NULL on fail,
 * returns pointer if x and y is the same,
 * else returns new pointer
 */
void *mem_alloc(void *p, unsigned int x, unsigned int y)
{
	unsigned int i = 0;
	char *a;

	if (p == NULL)
	{
		a = malloc(y);
		return (a);
	}

	if (y == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}

	if (y == x)
	{
		return (p);
	}

	a = malloc(y);

	if (a == NULL)
	{
		return (NULL);
	}

	for (; i < x ; i++)
	{
		a[i] = ((char *)p)[i];
	}

	free(p);

	return (a);
}

/**
 * split - this function is used to split a line
 * @a: the line to be used
 * @b: the character where the line should be split
 * Return: returns a double pointer
 */
char **split(char *a, char *b)
{
	char **j;
	int buff_size = 1024, x = 0;

	j = malloc(sizeof(char *) * buff_size);
	if (!j)
	{
		exit(99);
	}

	j[x] = strtok(a, b);
	x++;

	while (1)
	{
		j[x] = strtok(NULL, b);
		if (x >= buff_size)
		{
			buff_sizxe += buff_size;
			j = mem_alloc(j, buff_size, buff_size * (sizeof(char *)));
			if (!j)
			{
				exit(98);
			}
		}
		if (j[x] == NULL)
		{
			break;
		}

		x++;
	}

	return (j);
}
