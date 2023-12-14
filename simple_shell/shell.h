#ifndef SHELL_H
#define SHELL_H

/* the header files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

extern char **environ;

/* STDOUT_PUT FUNCTION */
void _printf(const char *user_string);
int _putchar(char c);
void _puts(char *str);

/* strings functions */

char *_memset(char *ptr, char val, unsigned int num);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, char *con);
int _strlen(char *str);
char *_strdup(char *string);
int _strspl(char *string);

/* built in functions */

int _built_in(char **ar, char *buf, int logout);
int biltin_cd(char **ar);
/* PATH & env functions */

char *PATH_buffer(char **ar, char *p, char *dup);
int spli_PATH(char *string);
char *PATH_concat(char *tmp, char **ar, char *token);
int comp_PATH(const char *str1, const char *str2);
int _env(void);
char *get_environ(const char *name);

/* tokenize and execute functions  and more functions */

int display_prompt(void);
char *read_user_command(void);
char **tokenize(char *buffer);
int execute(char **argv, char *buffer, char *pathbuffer);
#endif
