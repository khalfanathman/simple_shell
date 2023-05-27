#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
char *_getenv(char *name);
char *_strconcat(char *str1, char *str2);
char *_strcpy(char *path);
/**
 * path_directories - makes paths and searches for a program in set folders
 * @program: what the user typed as a command on prompt
 * @found_program: string pointer set when program was found successfully
 */

void path_directories(char *program, char **found_program)
{	int i;
	char *path_value = getenv("PATH"), *cap;
	char *token, *cat1, *cat2;
	struct stat st;

	cap = _strcpy(path_value);

	for (i = 0; ; i++, cap = NULL)
	{
		token = strtok(cap, ":");
		if (token == NULL)
			break;
		cat1 = _strconcat(token, "/");
		cat2 = _strconcat(cat1, program);
		if (stat(cat2, &st) == 0)
			*found_program = cat2;
		else if (stat(program, &st) == 0)
			*found_program = program;
	}
}
