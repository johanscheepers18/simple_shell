#include "shell.h"

int exec(int *x, char **_args, char **_argv, char **a)
{
    int y = 0;
    char *b[] = {"cd", "pwd", "exit", "env"};

    for (; y < 4 ; y++)
    {
        if (comp_str(_args[0], b[y]) == 0)
        {
            return (command_selec(_args, a));
        }
    }

    return (exe_handler(x, _args, _argv, a));
}

int exe_handler(int *x, char **_args, char **_argv, char **a)
{
    int y, z, c = 0, b;
    char *i = NULL;

    b = _status(&i, &c, _args[0], *x, _argv[0], a);

    if (i != NULL)
    {
        c++;
        z = fork();

        if (z == 0)
        {
            execve(i, _args, NULL);
        }
        else if (z < 0)
        {
            perror("Command not found");
        }
        else{
            do 
            {
                waitpid(z, &y, WUNTRACED);
            } while (!WIFEXITED(y) && !WIFSIGNALED(y));
        }
    }
    if (c == 0)
    {
        if (b != 1)
        {
            _printf("%s: %d: %s: unable to locate\n", _argv[0], *x, _args[0]);
        }
    }
    if (c == 2)
    {
        free(i);
    }
    return (1);
}