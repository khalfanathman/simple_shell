#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * rev_str - Reverse the str of string
 * @str: The pointer input string to be reversed
 *
 * Return: does not return;
 */
void rev_str(char **str)
{
	int len = _strlen(*str), i = 0;
	char *str1 = malloc(sizeof(char) * len);
	char *tem = malloc(sizeof(char) * len);

	str1 = copy_str(str1, *str);

	while (i < len)
	{
		tem[i] = str1[len - i - 1];
		i++;
	}

	*str = copy_str(*str,tem);
	free(str1);
	free(tem);
}
/**
 * concat_str - concatenates the src to dest
 * @dest: The input string to be concatenated to
 * @src: The input string to be concatenated from
 * Return: concatenated string;
 */
char *concat_str(char **dest, char *src)
{
	size_t total_len = _strlen(*dest) + _strlen(src) + 1;
	char *newArr = malloc(sizeof(char) * total_len);
	size_t i, j = 0;

	for (i = 0; (*dest)[i] != '\0'; i++)
	{
		newArr[i] = (*dest)[i];
	}

	for (; src[j] != '\0'; j++, i++)
	{
		newArr[i] = src[j];
	}

	newArr[i] = '\0';
	return (newArr);
}
