#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "main.h"
#include <stdbool.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define UNUSED(x) (void)(x)

/**
 * main - simple shell
 * @argc: counts the number of arguments given
 * @argv: array of arguments with length argc
 * @envp: array of environment variables
 * Return: always return 0;
 */

int main(int argc, char *argv[], char **envp)
{
	size_t size = 0;
	ssize_t chRead;
	shell_var shell;

	initialize_shell(&shell);
	UNUSED(argc);
	signal(SIGINT, sigint_handler);
	while (shell.PROMPT)
	{
		if (!isatty(STDIN_FILENO))
			shell.PROMPT = false;
		if (shell.PROMPT)
			_puts("cshell$ ");
		chRead = getline(&(shell.buf), &(shell.size), stdin);
		if ((shell.buf)[0] == '\r' || (shell.buf)[0] == '\n')
		{
			(shell.process_id)++;
			continue;
		}
		if (chRead != -1)
			shell.fin = setArray(&shell, &(shell.buf), size);
		else
			exit(EXIT_SUCCESS);
		if (compare_str((shell.fin)[0], "exit") == 0)
		{
			exit(0);
		}
		shell.command = check_cmd_exist(&shell, (shell.fin)[0]);
		if (shell.command != NULL)
		{
			execute_command(&shell, shell.fin, envp);
		}
		else
		{
			not_found(argv[0], (shell.fin)[0], shell.process_id, "not found");
			(shell.process_id)++;
		}
		fflush(stdin);
	}
	return (0);
}
