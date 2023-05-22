#include "main.h"
/**
 * initialize_shell - Initializes the shell structure.
 * @shell: Pointer to the shell structure.
 * @envp: environment variables array
 */
void initialize_shell(shell_var *shell, char **envp)
{
	shell->PROMPT = true;
	shell->buf = NULL;
	shell->size = 0;
	shell->chRead = 0;
	shell->finArr = NULL;
	shell->fin = NULL;
	shell->environs = envp;
	shell->PATH = _getenv("PATH", envp);
	shell->command = NULL;
	shell->process_id = 1;
	shell->num_tokens = 0;

}
