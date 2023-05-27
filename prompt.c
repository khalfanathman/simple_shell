#include "header.h"
#define UNUSED(x) (void)(x)
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
	char **stringArgumentsArray;
	char *commandlineArgs = NULL, *found_program = NULL;
	size_t n = 0;
	ssize_t charactersRead;

	UNUSED(ac);
	UNUSED(av);

	_puts("simple_Shell ($) ");

	while ((charactersRead = getline(&commandlineArgs, &n, stdin)) != -1)
	{
		stringArgumentsArray = tokenizer(commandlineArgs);

		if (_strcmp(stringArgumentsArray[0], "exit") == 0)
		{
			free(commandlineArgs);
			exit(0);
		}
		path_directories(stringArgumentsArray[0], &found_program);
		execute(found_program, stringArgumentsArray, env);
		found_program = NULL;
		_puts("simple_Shell ($) ");
	}
	free(commandlineArgs);
	return (0);
}
