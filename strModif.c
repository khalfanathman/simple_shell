#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * rev_str - Reverse the str of string
 * @str: The input string to be reversed
 *
 * Return: does not return;
 */
void rev_str(char *str)
{
	int start = 0;
	int end = 0;
	char temp;

	while (str[end] != '\0')
	{
		end++;
	}

	end--;

	while (start < end)
	{
		switch (str[start])
		{
			case '\0':
				break;

			default:
				switch (str[end])
				{
					case '\0':
						break;

					default:
						temp = str[start];
						str[start] = str[end];
						str[end] = temp;
						start++;
						end--;
						break;
				}

				break;
		}
	}
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
