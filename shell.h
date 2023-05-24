#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

char **_token(char *s, char *del);
void _token_free(char **tok);
char *printenv(char *a, char **env);
int interpreter(char *c);
int _env(char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *c(char *p, char *arr);
int (*r(char **i, char *fpath))(char *, char **, char **);
int _exec(char **i, char *fpath, char **env);
#endif
