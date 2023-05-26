#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The environment variable to retrieve.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(char *var)
{
	char *val = NULL, *copy = NULL;
	char **env = environ, *str;

	while (*env != NULL)
	{
		str = *env++;
		copy = copy_str(copy, str);
		strtok(copy, "=");

		if (compare_str(var, copy) == 0)
		{
			val = strtok(NULL, "=");
			return (val);
		}
	}

	free(env);
	return (NULL);
}
