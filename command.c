#define _DEFAULT_SOURCE
#include "main.h"


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
	copy_str(filepath, path_entry);
	concat_str(filepath, "/");
	concat_str(filepath, cmd);
	return (*filepath);
}

/**
 * check_cmd_exist - Checks if a cmd exists in the PATH environment variable.
 *
 * @term_cm: Command to check.
 * @shell: The pointer to struct variables to execute.
 * Return: The command if it exists, NULL otherwise.
 */

char *check_cmd_exist(shell_var *shell, char *term_cm)
{
	shell_var *sh = shell;
	char *copy = malloc(sizeof(char) * 120);
	char *PATH = _getenv("PATH", sh);
	char *fpath =  malloc(sizeof(char) * 120);
	char **arr;
	int i = 0;

	if (copy == NULL)
	{
		perror("malloc()");
		return (NULL);
	}

	copy_str(&copy, PATH);
	arr = set_array_cmd(sh, &copy, 10);
	array_sort(arr, 10);
	sh->copTok = copy;
	while (arr[i] != NULL)
	{
		if (compare_str(arr[i], term_cm) == 0)
		{
			return (term_cm);
		}

		fpath = conc_fpath(&fpath, arr[i], term_cm);

		if (access(fpath, X_OK) == 0)
		{
			free(copy);
			sh->fpath = fpath;
			return (fpath);
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
		/* free(shell->fin); */
		(sh->process_id)++;
		return;
	}
}
/**
 * control_d - Exits a command using CTR + D.
 * @shell: The pointer to struct variables.
 *
 * @envp: The array of environment variables.
 */
void control_d(shell_var *shell, char **envp)
{
	shell_var *sh = shell;

	if (sh->buf != NULL)
	{
		setArray(sh, &(sh->buf), sh->size);

		if ((sh->fin)[0] != NULL)
		{
			sh->command = check_cmd_exist(sh, (sh->fin)[0]);
		}

		if (sh->command != NULL)
		{
			execute_command(sh, sh->fin, envp);
			cleanup(sh);
			return;
		}

		cleanup(sh);
		free(sh->comStr);
		free(sh->pathStr);
	}
	exit(EXIT_SUCCESS);
}
