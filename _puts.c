#include "header.h"

/**
 * _puts - write to standard output
 * @str: string to write to stdout file
 */

void _puts(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	len++;

	write(STDOUT_FILENO, str, len);
}
