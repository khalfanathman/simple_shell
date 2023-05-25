#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The environment variable to retrieve.
 * @sh: shell variables
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(char *var, shell_var *sh)
{
	char *val = NULL;
	char *copy = NULL;
	char *token;
	char **env = sh->environs;
	int i = 0;

	while (env[i] != NULL)
	{
		copy = malloc(strlen(env[i]) + 1);
		copy_str(&copy, env[i]);
		token = strtok(copy, "=");

		if (compare_str(var, token) == 0)
		{
			token = strtok(NULL, "=");
			val = malloc(strlen(token) + 1);
			copy_str(&val, token);
			free(copy);
			sh->getVal = val;
			return (val);
		}

		i++;
		free(copy);
	}

	free(val);
	return (NULL);
}
