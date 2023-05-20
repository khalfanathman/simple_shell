#define _DEFAULT_SOURCE
#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * conc_fpath - Concatenates the file path.
 * @filepath: Pointer to the file path.
 * @path_entry: Path entry.
 * @cmd: Command to concatenate.
 *
 * Return: The concatenated file path.
 */

char *conc_fpath(char **filepath, char *path_entry, char *cmd)
{
	*filepath = copy_str(*filepath, path_entry);
	*filepath = concat_str(filepath, "/");
	*filepath = concat_str(filepath, cmd);

	return (*filepath);
}

/**
 * check_cmd_exist - Checks if a cmd exists in the PATH environment variable.
 * @term_cm: Command to check.
 *
 * Return: The command if it exists, NULL otherwise.
 */

char *check_cmd_exist(shell_var *shell, char *term_cm)
{
	shell_var *sh = shell;
	char *copy = NULL, *path = getenv("PATH");
	int i = 0;
	char *fpath = malloc(sizeof(char *) * 11);
	char **arr, *commnd;

	if (path == NULL || fpath == NULL)
	{
		perror("path");
		exit(EXIT_FAILURE);
	}

	copy = copy_str(copy, path);
	arr = set_array_cmd(sh,&copy, 10);
	array_sort(arr, 10);

	while (arr[i] != NULL)
	{
		if (compare_str(arr[i], term_cm) == 0)
		{
			return (term_cm);
		}

		fpath = conc_fpath(&fpath, arr[i], term_cm);

		if (access(fpath, X_OK) == 0)
		{
			commnd = copy_str(term_cm, fpath);
			free(fpath);
			fpath = NULL;
			return (commnd);

		}

		i++;
		free(fpath);
		fpath = NULL;
	}

	return (NULL);
}
/**
 * execute_command - Executes a command using execve.
 * @shell: The pointer to struct variables to execute.
 * @fin: The array of command arguments.
 * @envp: The array of environment variables.
 */
void execute_command(shell_var *shell, char **fin, char **envp)
{
	pid_t child_pid;
	shell_var *sh = shell;
	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(sh->command, fin, envp) == -1)
		{
			(sh->process_id)++;
			perror(fin[0]);
			return;
		}
	}

	else
	{
		wait(NULL);
		sh->command = NULL;
		free(fin);
		(sh->process_id)++;
		return;
	}
}