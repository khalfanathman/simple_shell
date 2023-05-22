#include "main.h"

/**
 * conf_environs - shell prompt to wait for user input
 *
 * @shell: struct variable that can be used through out.
 * @set: comand to set
 *
 * Return: returns true or false
 */
void conf_environs(shell_var *shell, char *set)
{
	if (compare_str(set, "setenv") == 0)
		_setenv(shell->fin[1], shell->fin[2], shell->environs);
	if (compare_str(set, "unsetenv") == 0)
		_unsetenv(shell->fin[1], shell->environs);
}
/**
 * input_check - checks for a number of condition input
 *
 * @shell: struct variable that can be used through out.
 * @program_name: program name
 * @size: size of the array that will be used
 *
 * Return: returns true or false
 */
bool input_check(shell_var *shell, char *program_name, size_t size)
{
	if ((shell->buf)[0] == '\r' || (shell->buf)[0] == '\n')
	{
		(shell->process_id)++;
		return (true);
	}

	if (shell->chRead != -1)
	{
		shell->fin = setArray(shell, &(shell->buf), size);
	}

	else
	{
		control_d(shell, shell->environs);
	}

	if (compare_str(shell->fin[0], "setenv") == 0)
	{
		conf_environs(shell, (shell->fin)[0]);
		return (true);
	}
	else if (compare_str(shell->fin[0], "unsetenv") == 0)
	{
		if (shell->fin[1] == NULL)
		{
			usage_err("unsetenv: not enough arguments");
			return (true);
		}
		else
		{
			conf_environs(shell, (shell->fin)[0]);
			return (true);
		}
	}
	if (compare_str((shell->fin)[0], "exit") == 0)
	{
		exiting(shell, program_name);
		return (true);
	}
	return (false);
}

/**
 * shell_loop - shell prompt to wait for user input
 *
 * @shell: struct variable that can be used through out
 * @size: size of the array that will be used
 * @program_name: program name
 *
 */
void shell_loop(shell_var *shell, size_t size, char *program_name)
{
	while (shell->PROMPT)
	{
		if (!isatty(STDIN_FILENO))
			shell->PROMPT = false;

		if (shell->PROMPT)
			_puts("cshell$ ");

		shell->chRead = _getline(&(shell->buf), &(shell->size), stdin);

		/* INPUT CHECK */
		if (input_check(shell, program_name, size))
			continue;

		shell->command = check_cmd_exist(shell, (shell->fin)[0]);

		if (shell->command != NULL)
		{
			execute_command(shell, shell->fin, shell->environs);
			cleanup(shell);
		}

		else
		{
			not_found(program_name, (shell->fin)[0], shell->process_id, "not found");
			(shell->process_id)++;
		}
	}
}
