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
	shell_var shell;

	initialize_shell(&shell, envp);
	UNUSED(argc);
	signal(SIGINT, sigint_handler);
	shell_loop(&shell, size, argv[0]);
	return (0);
}
