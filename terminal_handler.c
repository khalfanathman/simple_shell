#include "main.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * sigint_handler - Handles the SIGINT signal.
 * @sig: The signal number.
 */
void sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		_exit(0);
	}
}
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
	sh->chRead = 0;
	shell->num_tokens = 0;
	sh->command = NULL;
	sh->num_tokens = 0;
	sh->size = 0;
	sh->finArr = NULL;
	sh->buf = NULL;
	sh->fin = NULL;
	fflush(stdin);
}
