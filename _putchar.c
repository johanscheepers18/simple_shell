#include "shell.h"

int _putchar(char s, int *x)
{
    *x += 1;

    return (write(1, &s, 1));
}