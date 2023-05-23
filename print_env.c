#include "main.h"
/**
 * print_env - Prints the elements of an environment variable array.
 * @env: The array of environment variable strings.
 */
void print_env(char **env)
{
	char **environ = env;
	int k = 0;

	while (environ[k] != NULL)
	{
		write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}
