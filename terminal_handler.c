#include "main.h"

/**
 * cleanup - clean up the varable used before next iteration.
 * @shell: Pointer to the shell structure to be cleaned.
 */
void cleanup(shell_var *shell)
{
	shell_var *sh = shell;

	free(sh->buf);
	free(sh->fin);
	free(sh->finArr);
	free(sh->comStr);
	free(sh->pathStr);
	free(sh->fpath);
	free(sh->PATH);
	free(sh->getVal);
	free(sh->command);
	sh->chRead = 0;
	sh->num_tokens = 0;
	sh->command = NULL;
	sh->num_tokens = 0;
	sh->size = 0;
	sh->finArr = NULL;
	sh->buf = NULL;
	sh->fin = NULL;
	sh->comStr = NULL;
	sh->fpath = NULL;
	sh->copTok = NULL;
	sh->pathStr = NULL;
	fflush(stdin);
}
/**
 * power - calculate power of a number.
 * @base: base of power.
 * @exponent: exponent to be used.
 *
 * Return: return the result of power.
 */
int power(int base, int exponent)
{
	int i = 0, result = 1;

	for (i = 0; i < exponent; i++)
		result *= base;

	return (result);
}

/**
 * exiting - converts str to int status.
 * @shell: stract passed to access the array of commands.
 * @prog_name: string to be converted.
 */
void exiting(shell_var *shell, char *prog_name)
{
	int status = 0;
	char *str = NULL;
	shell_var *sh = shell;

	str = sh->fin[1];

	if (str != NULL)
	{
		status = str_to_int(str, sh->process_id, prog_name);

		if (status >= 0)
		{
			cleanup(sh);
			exit(status);
		}
		else
		{
			cleanup(sh);
			return;
		}
	}

	else
	{
		free(sh->fin);
		free(sh->buf);
		free(sh->comStr);
		/* cleanup(shell); */
		exit(status);
	}
}

