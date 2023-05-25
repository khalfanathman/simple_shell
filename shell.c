
#include "main.h"

#define UNUSED(x) (void)(x)
/**
 * main - simple shell
 * @argc: counts the number of arguments given
 * @argv: array of arguments with length argc
 * @envp: array of environment variables
 * Return: always return 0;
 */
int main(int argc, char *argv[], char **envp)
{
	size_t size = 10;
	shell_var shell;

	shell.PROMPT = true;
	shell.buf = NULL;
	shell.size = 0;
	shell.chRead = 0;
	shell.finArr = NULL;
	shell.fin = NULL;
	shell.environs = envp;
	shell.command = NULL;
	shell.process_id = 1;
	shell.num_tokens = 0;
	shell.comStr = NULL;
	shell.fpath = NULL;
	shell.copTok = NULL;
	shell.pathStr = NULL;
	shell.getVal = NULL;
	/* initialize_shell(&shell, envp); */
	UNUSED(argc);
	signal(SIGINT, sigint_handler);
	shell_loop(&shell, size, argv[0]);
	return (0);
}
