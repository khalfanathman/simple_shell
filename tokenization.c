#include "main.h"
/**
 * _extract_src - Extract strings from a src
 * @src: The srcing to be extracted_srcized
 * @delim: The delimiter character
 *
 * Return: Pointer to the next extracted_src extracted from 'src',
 *         or NULL if no more extracted_srcs are found.
 */

char *_extract_src(char *src, char *delim)
{
	static char *remaing;
	char *extracted_src;
	int i = 0;

	if (src != NULL)
	{
		remaing = src;
	}
	if (remaing == NULL || *remaing == '\0')
	{
		return (NULL);
	}
	extracted_src = malloc(_strlen(remaing) + 1);

	if (extracted_src == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (*remaing != '\0')
	{
		if (_strchr(delim, *remaing) == NULL)
		{
			extracted_src[i] = *remaing;
			i++;
			remaing++;
		}

		else
		{
			extracted_src[i] = '\0';
			remaing++;
			/* src = remaing; */
			return (extracted_src);
		}
	}

	extracted_src[i] = '\0';
	return (extracted_src);
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
