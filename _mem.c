#include "shell.h"

void *mem_alloc(void *p, unsigned int x, unsigned int y)
{
    unsigned int i = 0;
	char *a;

    if (y == x)
    {
        return (p);
    }

    if (y == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}

    a = malloc(y);

    if (a == NULL)
	{
		return (NULL);
	}

    if (p == NULL)
    {
        return (a);
    }

    while (i < y && i < x)
    {
        a[i] = ((char *) p)[i];
        i++;
    }
    free(p);
    return (a);
}