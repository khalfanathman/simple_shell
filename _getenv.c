#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The environment variable to retrieve.
 * @envp: environment variable array
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(char *var, char **envp)
{
	char *val = NULL, *copy = NULL, *cp;
	char **env = envp;
	int i = 0;

	while (env[i] != NULL)
	{
		cp = copy_str(copy, env[i]);
		copy = _extract_src(cp, "=");

		if (compare_str(var, copy) == 0)
		{
			/**
			 * *cp = *(cp + _strlen(copy));  <= i found this
			 * replaces char located at strlen
			 *
			 */
			val = (cp + _strlen(copy) + 1);
			return (val);
		}

		i++;
	}

	return (NULL);
}
