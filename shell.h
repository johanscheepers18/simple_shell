#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/*str_man.c file functions*/
unsigned int str_length(char *str);
char *_rl(void);
char *cat_str(char *dest, char *src);
char *_duplicate_str(char *str);

/*str_man_2.c file functions*/
char *eq_check(char *str);
int *comp(char *a, char *b);

/*_print.c file functions*/
void _puts(char *str);
int _putchar(char s);

/*_mem.c file functions */
int exec(char **a);
void *mem_alloc(void *p, unsigned int x, unsigned int y);
char **split(char *a, char *b);

/*_paths.c file functions */
char *env(char **a, char *b);
char *_path(char **a, char **b);
char **path_finder(char **a);

#endif
