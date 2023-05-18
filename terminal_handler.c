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

