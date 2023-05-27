#include <unistd.h>

/**
 * _strcmp - checks if two strings are exactly the same
 * @string1: first string input
 * @string2: second string input
 *
 * Return: 0 if the strings are the same: 1 if otherwise
 */

int _strcmp(char *string1, char *string2)
{
	while (*string1 && string2)
	{
		if (*string1++ != *string2++)
			return (1);
	}

	return (0);
}
