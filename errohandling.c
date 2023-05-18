#include <unistd.h>
#include "main.h"

/**
 * int_To_Str - Converts an integer to a string.
 * @str: Pointer to the destination string.
 * @num: The integer to convert.
 */
void int_To_Str(char *str, int num)
{
	int i = 0;
	int is_Neg = 0;

	if (num < 0)
	{
		is_Neg = 1;
		num = -num;
	}

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_Neg)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	rev_str(str);
}

/**
 * not_found - Handles the "not found" case.
 * @prog: Name of the program.
 * @comd: Command that was not found.
 * @pid_no: Process ID number.
 * @msg: Error message.
 */

void not_found(char *prog, char *comd, int pid_no, char *msg)
{
	char str[4];

	int_To_Str(str, pid_no);
	_puts(prog);
	_puts(": ");
	_puts(comd);
	_puts(": ");
	_puts(str);
	_puts(": ");
	_puts(msg);
	_puts("\n");
}
