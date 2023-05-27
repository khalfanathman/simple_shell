#include "header.h"

/**
 * tokenizer - make a array of string tokens
 * @commandlineArgs: sting recieved from user
 *
 * Return: array of strings
 */

char **tokenizer(char *commandlineArgs)
{
	size_t i;
	char *preToken, *token;
	static char *stringArgumentsArray[5];

	preToken = strtok(commandlineArgs, "\n"); /*chop-off the newline character*/

	for (i = 0; ; i++, preToken = NULL)
	{
		token = strtok(preToken, " ");
		if (token == NULL)
			break;
		stringArgumentsArray[i] = token;
		stringArgumentsArray[i + 1] = NULL;
	}
	return (stringArgumentsArray);
}
