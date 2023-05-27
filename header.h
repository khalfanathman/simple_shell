#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char *_getenv(char *name);
char *_strconcat(char *str1, char *str2);
char *_strcpy(char *path);
void path_directories(char *program, char **found_program);
int _strcmp(char *string1, char *string2);
void _puts(char *str);

#endif /* HEADER_H */
