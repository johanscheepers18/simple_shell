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

//_print.c functions
int _printf(const char *a, ...);
void chr_print(va_list x, int *y);
void str_print(va_list x, int *y);
void int_print(va_list x, int *y);
int _printn(int x, int *y);
#endif