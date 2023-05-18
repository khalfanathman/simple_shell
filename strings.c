#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>


/**
 * copy_str - it copies an array of str from user
 *              stdin
 * @dest: the string to be conctenated to
 * @src: the string to be concatenet
 *
 * Return: it returns an a copy of the array.
 */
char *copy_str(char *dest, char *src)
{
	int i, len = _strlen(src);

	dest = malloc((len + 1) * sizeof(char));
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[len] = '\0';
	return (dest);
}

/**
 * compare_str_long - Compares two strings and returns the shorter one.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: Pointer to the shorter string.
 */
char *compare_str_long(char *str1, char *str2)
{
	if (_strlen(str1) < _strlen(str2))
	{
		return (str1);
	}

	else if (_strlen(str1) >  _strlen(str2))
	{
		return (str2);
	}

	else
	{
		return (str1);

	}


}
/**
 * compare_str - checks if two strs are equal
 * @str1: string 1 to be passed
 * @str2: str2 to be passed for checking
 *
 *
 * Return: returns -1  if dont match and 0 if equal
 */

int compare_str(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}

		i++;
	}


	return (0);
}
/**
 * _strlen - Calculate the length of a null-terminated string
 * @line: The input string
 *
 * Return: The length of the string (excluding the null terminator)
 */
size_t _strlen(char *line)
{
	size_t length = 0;

	while (line[length] != '\0')
	{
		length++;
	}

	return (length);
}
/**
 * _puts - prints strings to stdoute.
 * @str: The string to be printed.
 *
 * Return: returns void.
 */
void _puts(char *str)
{
	size_t len = _strlen(str) + 1;

	write(STDOUT_FILENO, str, len);
}
