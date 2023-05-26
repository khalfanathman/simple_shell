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

bool input_check(shell_var *shell, char *command, char *prg_name, char **envp);

/**
 * main - simple shell
 * @argc: counts the number of arguments given
 * @argv: array of arguments with length argc
 * @envp: array of environment variables
 * Return: always return 0;
 */

int main(int argc, char *argv[], char **envp)
{
	shell_var shell;
	size_t size = 0;
	ssize_t chRead;

	UNUSED(argc);
	signal(SIGINT, sigint_handler);
	initialize_shell(&shell, envp);
	while (shell.PROMPT)
	{
		size = 0;
		if (!isatty(STDIN_FILENO))
			shell.PROMPT  = false;
		if (shell.PROMPT)
			_puts("cshell$ ");
		chRead = getline(&shell.buf, &size, stdin);
		if (shell.buf[0] == '\r' || shell.buf[0] == '\n')
		{
			shell.process_id++;
			continue;
		}
		if (chRead != -1)
			shell.fin = setArray(&shell, &shell.buf, size);
		else
			exit(EXIT_SUCCESS);
		if (compare_str(shell.fin[0], "exit") == 0)
		{
			exiting(&shell, argv[0]);
		}
		shell.command = check_cmd_exist(&shell, shell.fin[0]);
		if (shell.command != NULL)
		{
			/* printf(shell.command); */
			if (input_check(&shell, shell.command, argv[0], envp))
				continue;
		}
		else
		{
			not_found(argv[0], shell.fin[0], shell.process_id, "not found");
			shell.process_id++;
			continue;
		}
		fflush(stdout);
	}
	return (0);
}
/**
 * input_check - checks for a number of condition input
 *
 * @shell: struct variable that can be used through out.
 * @command: command passed if pass commad check.
 * @prg_name: program name
 * @envp: environment variables
 *
 * Return: returns true or false
 */
bool input_check(shell_var *shell, char *command, char *prg_name, char **envp)
{
	pid_t child_pid;
	/* check command exist */
	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(command, shell->fin, envp) == -1)
		{
			/* cleanup(shell); */
			shell->process_id++;
			perror(prg_name);
			fflush(stdout);
			return (false);
		}
	}
	else
	{
		wait(NULL);
		cleanup(shell);
		/* shell->process_id++; */
		fflush(stdout);
		return (false);
	}
		return (true);
}
