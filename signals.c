#include "main.h"
/**
 * sigint_handler - Handles the SIGINT signal.
 * @sig: The signal number.
 */
void sigint_handler(int sig)
{
	/* Shell->PROMPT = false; */
	if (sig == SIGINT)
	{
		exit(0);
		/* kill(0,sig); */
		/* exiting(0); */
	}
}
