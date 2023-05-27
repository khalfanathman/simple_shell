#include "header.h"

/**
 * execute - performs forking and execve system call to run programs
 * @found_program: program to run
 * @stringArgumentsArray: array of program and its options
 * @env: copy of enviroment variable
 */

void execute(char *found_program, char **stringArgumentsArray, char **env)
{
	static int status;
	pid_t pid;

	if (found_program != NULL)
	{
		pid = fork();

		if (pid == 0)
		{
			if (execve(found_program, stringArgumentsArray, env) == -1)
				perror("ERROR:");
		} else
			wait(&status);
	} else
		perror(stringArgumentsArray[0]);
}
