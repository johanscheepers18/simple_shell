#include "shell.h"

int _printf(const char *a, ...)
{
    int x = 0, y = 0, z = 0;
    int *p;
    va_list pr;

    if (a == NULL)
    {
        return (-1);
    }

    p = &z;
    va_start(pr, a);

    while (a && a[x])
    {
        if (a[x] == '%')
        {
            y = print_sel(a, x, pr, p);
            if (y == -1)
            {
                return (-1);
            }
            if (!y)
            {
                va_end(pr);
                return (z);
            }
            x += y;
            continue;
        }
        else{
            _putchar(a[x], p);
        }
        x++;
    }
    va_end(pr);
    return (z);
}

void chr_print(va_list x, int *y)
{
    char a = (char) va_arg(x, int);

    _putchar(a, y);
}

void str_print(va_list x, int *y)
{
    int a = 0, b = 0;
    char *str = va_arg(x, char*), nul[] = "(null)";

    if (str == NULL)
    {
        while (nul[a])
        {
            _putchar(nul[a], y);
            a++;
        }
    }
    else{
        while (str[b])
        {
            _putchar(str[b], y);
            b++;
        }
    }
}

void int_print(va_list x, int *y)
{
    int a, b = va_arg(x, int);

    a = _printn(b, y);
    y += a;
}

int _printn(int x, int *y)
{
    unsigned int z = x;
    int a;

    if (x < 0)
    {
        _putchar('-', y);
        z *= -1;
        a = 1;
    }
    if (z / 10)
    {
        _printn((z / 10), y);
    }

    _putchar(((z & 10) + '0'), y);

    while (z > 10)
    {
        z /= 10;
        a++;
    }
    a++;
    return (a);
}