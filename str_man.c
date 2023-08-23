#include "shell.h"

int comp_str(char *dest, char *src)
{
    int x = 0, y, z, a;

    while (dest[x] == src[x] && dest[x] != '\0' && src[x] != '\0')
    {
        x++;
    }

    y = (dest[x] - '0');
    z = (src[x] - '0');
    a = y - z;

    return (a);
}

char *duplicate_str(char *str)
{
    int x = 0, y = 0;
    char *a;

    if (str == NULL)
    {
        return (NULL);
    }

    while (str[x])
    {
        x++;
    }

    x++;

    a = (char *) malloc(sizeof(char) * x);
    if (a == NULL)
    {
        return (NULL);
    }

    for (; y < x ; y++)
    {
        a[y] = str[y];
    }

    return (a);
}

char *join_str(char *dest, char *src)
{
    int x = 0, y = 0, z = 0, a = 0;
    char *c;

    if (dest == NULL)
    {
        dest = "";
    }
    if (src == NULL)
    {
        src = "";
    }

    while (dest[x])
    {
        x++;
    }
    while (src[y])
    {
        y++;
    }
    y++;

    c = (char *) malloc((x + y) * sizeof(char));
    if (c == NULL)
    {
        return (NULL);
    }
    for (; z < x ; z++)
    {
        c[z] = dest[z];
    }
    for (; a < y ; a++)
    {
        c[a + 1] = src[a];
    }

    return (c);
}

int chr_count(char *s)
{
    int x = 0, y = 0;

    while (s[x])
    {
        if (s[x] != ' ' && s[x] != '\t' && s[x] != '\n')
        {
            y++;
        }
        x++;
    }

    return (y);
}