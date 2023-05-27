#include <stdlib.h>
#include <stdio.h>

/**
 * _strcpy - allocate new memory location and copy
 * string into it.
 * @path: string to  copy from
 *
 * Return: pointer to newly made string
 */

char *_strcpy(char *path)
{
	int i = 0, j;
	static char /***/newPath[50] /*= NULL*/;

	while (path[i] != '\0')
		i++;

/*
 *	newPath = malloc(i + 1);

	if (newPath == NULL)
		free(newPath);
*/

	for (j = 0; j <= i; j++)
		newPath[j] = path[j];

	return (newPath);
}
