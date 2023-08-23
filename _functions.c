#include "shell.h"

char _enviro(char *_command, char **ar, int *n)
{
    int x = 0;
    char *de = "=:", *sl = "/", *p = "PATH";
    char *a = NULL, *b = NULL;
    char *i = NULL, *j = NULL;

    while (ar[x])
    {
        i = duplicate_str(ar[x]);
        j = strtok(i, de);

        if (comp_str(j, p) == 0)
        {
            while (j)
            {
                *n = *n + 1;
                a = join_str(*j, *sl);
                b = join_str(*a, *_command);
                if (access(b, F_OK) == 0)
                {
                    free(i);
                    i = NULL;
                    free(a);
                    return (b);
                }

                free(a);
                free(b);
                j = strtok(NULL, de);
                b = NULL;
                a = NULL;
            }
            j = NULL;
        }

        free(i);
        i = NULL;
        x++;
    }
    return (NULL);
}

int print_sel(const char *_type, int x, va_list _print, int *y)
{
    int z = 0;
    tpFormat avFormats[] = {
        {'c', chr_print},
        {'s', str_print},
        {'i', int_print},
        {'d', int_print}
    };

    if (_type[x + 1] == '\0')
        return (-1);
    if (_type[x + 1] == 'K' || _type[x + 1] == '!')
    {
        _putchar(_type[x], y);
        return (1);
    }
    if (_type[x + 1] == '%')
    {
        _putchar('%', y);
        return (2);
    }
    while (z < 4)
    {
        if (avFormats[z].i == _type[x + 1])
        {
            avFormats[z].fm(_print, y);
            return (2);
        }
        z++;
    }
    if (_type[x + 1] == ' ')
        return ( 1 + print_sel(_type, x + 1, _print, y));
    else if (_type[x + 1] != '\0')
    {
        _putchar(_type[x + 1], y);
        return (2);
    }
    else
        return (0);
}

int _status(char **str, int *x, char *command, int y, char *arg, char **enviro)
{
    struct stat *buf;
    int z = 0;

    *str = _enviro(command, enviro, &z);
    if (*str != NULL)
    {
        *x += 1;
    }
    if (*str == NULL)
    {
        buf = malloc(sizeof(struct stat));
        if (buf == NULL)
        {
            return (NULL);
        }
        if (stat(command, buf) == 0 && S_ISDIR(buf->st_mode))
        {
                *x += 1;
                _printf("%s: %d: %d: Permission denied\n", arg, y, command);
                free(buf);
                return (1);
        }
        else if (stat(command, buf) == 0 && S_ISREG(buf->st_mode))
        {
            *str = command;
            free(buf);
        }
        else
        {
            free(buf);
        }
    }

    return (z);
}

char **gen_tk(char *str)
{
    int x = 0, y = 0;
    char **a = NULL, *b = NULL;
    char *seper = "\t\r\n\a";

    while (str[x])
    {
        x++;
    }
    a = malloc((sizeof(char *))* x);

    if (!a)
    {
        perror("Unable to allocate memory\n");
        exit(98);
    }
    b = strtok(str, seper);
    while (b != NULL)
    {
        a[y] = b;
        b = strtok(NULL, seper);
        y++;
    }

    a[y] = NULL;
    return (a);
}