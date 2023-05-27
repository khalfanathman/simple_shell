#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
void path_directories(char *program, char **found_program);
int _strcmp(char *string1, char *string2);
void _puts(char *str);

/**
 * main - Entry prompt program: takes in commands and executes them
 * @ac: Number of arguments provided by user
 * @av: string array of all arguments obtained from user
 * @env: Null terminated array enviroment variables
 *
 * Return: returns 0
 */

int main(int ac, char **av, char **env)
{
	char *stringArgumentsArray[5];
	char *commandlineArgs = NULL, *token, *preToken, *found_program = NULL;
	size_t n = 0, i;
	ssize_t charactersRead;
	int status;
	pid_t pid;

	_puts("simple_Shell ($) ");

	/* read from standard input*/
	while ((charactersRead = getline(&commandlineArgs, &n, stdin)) != -1)
	{
		preToken = strtok(commandlineArgs, "\n"); /*chop-off the newline character*/

		for (i = 0; ; i++, preToken = NULL)
		{
			token = strtok(preToken, " ");
			if (token == NULL)
				break;
			stringArgumentsArray[i] = token;
			stringArgumentsArray[i + 1] = NULL;
		}

		if (_strcmp(stringArgumentsArray[0], "exit") == 0)
			exit(0);

		path_directories(stringArgumentsArray[0], &found_program);

		if (found_program != NULL)
		{
			pid = fork();

			if (pid == 0)
			{
				if (execve(found_program, stringArgumentsArray, env) == -1)
					perror("ERROR:");
			}
			else
				wait(&status);
		}
		else
			perror(stringArgumentsArray[0]);
		found_program = NULL;
		_puts("simple_Shell ($) ");
	}
	free(commandlineArgs);
	return (0);
}
