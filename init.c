#include "main.h"
/**
 * initialize_shell - Initializes the shell structure.
 * @shell: Pointer to the shell structure.
 */
void initialize_shell(shell_var *shell)
{
	/* Initialize the shell structure */
	shell->PROMPT = true;
	shell->buf = NULL;
	shell->size = 0;
	shell->chRead = 0;
	shell->finArr = NULL;
	shell->fin = NULL;
	shell->command = NULL;
	shell->process_id = 1;
	shell->num_tokens = 0;
	/* Initialize other variables as needed */
}
