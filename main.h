#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define PROMPT "$"

extern char **environ;
/* char *shell;*/
void exe(char **argv);

char *get_loc(char *command);

int _atoi(const char *s);

char *_strchr(const char *str, int character);

unsigned int isDelimiter(char c, const char *delimiters);

char *_strtok(char *str, const char *delimiters);

int _strlen(const char *arg);

void _strcpy(char *dest, const char *src);
/*void _exitt(char *, char **, int);*/
void _strcat(char *dest, const char *src);

char *_strdup(const char *src);
/*ssize_t _getline(char **, size_t *, FILE *);*/
int _strcmp(const char *str1, const char *str2);
void _setenv(char **);
void _unsetenv(char **);
void cd_command(char **);
#endif
