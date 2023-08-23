#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/signal.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct commands
{
    char *sel;
    int (*com)(char **)
} cmd_sel;

typedef struct tp_fm
{
    char *i;
    void (*fm)(va_list, int *);
}   tpFormat;

typedef void (*sighandler_t)(int);

//_print.c functions
int _printf(const char *a, ...);
void chr_print(va_list x, int *y);
void str_print(va_list x, int *y);
void int_print(va_list x, int *y);
int _printn(int x, int *y);

//_commands.c functions
int _cd(char **_args);
int _pwd(char **_args);
int _exit(char **_args);
int _env(char **_args);
int command_selec(char **_args, char **a);

//_exec.c functions
int exec(int *x, char **_args, char **_argv, char **a);
int exe_handler(int *x, char **_args, char **_argv, char **a);

//_functions.c functions
char _enviro(char *_command, char **ar, int *n);
int print_sel(const char *_type, int x, va_list _print, int *y);
int _status(char **str, int *x, char *command, int y, char *arg, char **enviro);
char **gen_tk(char *str);

//_mem.c functions
void *mem_alloc(void *p, unsigned int x, unsigned int y);

//_putchar.c
int _putchar(char s, int *x);

//str_man.c functions
int comp_str(char *dest, char *src);
char *duplicate_str(char *str);
char join_str(char *dest, char *src);
int chr_count(char *s);
#endif
