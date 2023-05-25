#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>

/**
 * str_contains - checks if a character is contained in a variable
 *
 * @str: the striing to inspect.
 * @ch: the character being ispected.
 *
 * Return: returns true if char found and false if not found.
 *
 */
bool str_contains(char *str, char ch)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			return (true);
		}

		i++;
	}

	return (false);
}
/**
 * _setenv - it set environment var for the current proccess
 *
 * @var: variable to be set.
 * @val: value to be set
 * @envp: array of environent varables.
 *
 */
void _setenv(char *var, char *val, char **envp)
{
	char *copy = NULL, *cp;
	char **env = envp;
	int i = 0;

	if (str_contains(val, '='))
	{
		usage_err("Usage: setenv VARIABLE VALUE");
		return;
	}

	while (env[i] != NULL)
	{
		cp = copy_str(copy, env[i]);
		copy = _extract_src(cp, "=");

		if (compare_str(var, copy) == 0)
		{
			env[i] = concat_str(&var, "=");
			env[i] = concat_str(&env[i], val);
			return;
		}

		i++;
	}

	env[i] = concat_str(&var, "=");
	env[i] = concat_str(&env[i], val);
	env[i + 1] = NULL;
}
/**
 * _unsetenv - it Remove environment var for the current proccess
 *
 * @var: variable to be removed.
 * @envp: array of environent varables.
 *
 */
void _unsetenv(char *var, char **envp)
{
	char *copy = NULL, *cp;
	char **env = envp;
	int i = 0, j = 0, k = 0;

	if (str_contains(var, '='))
	{
		usage_err("Usage: unsetenv VARIABLE");
		return;
	}

	while (env[k] != NULL)
		k++;

	while (env[i] != NULL)
	{
		cp = copy_str(copy, env[i]);
		copy = _extract_src(cp, "=");

		if (compare_str(var, copy) == 0)
		{
			j = i;
			break;
		}

		i++;
	}

	env[j] = env[k - 1];
	env[k - 1] = env[k];
}
