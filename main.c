#include "shell.h"

int main(int argc, char **argv, char **enviro)
{
    char *str = NULL, **a = NULL;
    char *n = "\n";
    int x = 1, y = 0, z = 1;
    size_t j;

    y = isatty(STDIN_FILENO);
    if (y)
    {
        _printf("#cisfun$ ");
    }
    while (x && (getline(&str, &j, stdin) != EOF))
    {
        if (chr_count(str) > 0)
        {
            if (comp_str(str, n) != 0)
            {
                a = gen_tk(str);
                x = exec(&z, a, argv, enviro);
                free(str);
                free(a);
                str = NULL;
                a = NULL;

                if (x != 0 && y)
                {
                    _printf("#cisfun$ ");
                }
                z++;
            }
        }
        else if (y != 0)
        {
            _printf("#cisfun$ ");
        }
    }

    if (y && x != 0)
    {
        _putchar('\n');
    }
    free(str);
    free(a);
    argc = argc;
    return (0);
}