#include "shell.h"

int _cd(char **_args)
{
    printf("Using the change directory function: %s\n", _args[0]);
    return (1);
}

int _pwd(char **_args)
{
    printf("This is the current working direcotry: %s\n", _args[0]);
    return (1);
}

int _ex(char **_args)
{
    char *x = "exit";

    if (comp_str(_args[0], x) == 0)
    {
        return (0);
    }

    return (1);
}

int _env(char **_args)
{
    int x = 0;

    while (_args[x])
    {
        _printf("%s\n", _args[x]);
        x++;
    }

    return (1);
}

int command_selec(char **_args, char **a)
{
    int x = 0;

    cmd_sel commands[] = {
        {"cd", _cd  },
        {"pwd", _pwd},
        {"exit", _ex},
        {"env", _env}
    };

    for (; x < 4; x++)
    {
        if (comp_str(commands[x].sel, _args[0]) == 0)
        {
            if (comp_str(commands[x].sel, "env") == 0)
            {
                return (commands[x].com(a));
            }
            else{
                return (commands[x].com(_args));
            }
        }
    }

    return (1);
}