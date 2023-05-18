#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
/**
 * copy_arr - it copies an array of str from user
 *              stdin
 * @src: a pointer to the arry of strings to be modified
 * @len: its the length of the array t be copied
 * Return: it returns an a copy of the array.
 */
char **copy_arr(char ***src, int *len)
{
	int i;

	char **argv_copy = (char **)malloc((*len + 1) * sizeof(char *));

	for (i = 0; i < *len; i++)
	{
		copy_str(argv_copy[i], *src[i]);
	}

	argv_copy[*len] = NULL;
	*src = argv_copy;
	/* free(argv_copy);  */
	return (argv_copy);
}
/**
 * setArray - it creates array of str from user
 *              stdin
 * @shell: Pointer to the shell structure.
 * @buffer: a pointer to the string to be modified
 * @size: size of the array.
 * Return: it returns an array of strings.
 */
char **setArray(shell_var *shell, char **buffer, size_t size)
{
	shell_var *sh = shell;
	char *token = NULL;
	char *tokens[10];

	char *copy = NULL;
	char **finArr = malloc(sizeof(char *) * size);

	int len, j;

	sh->num_tokens = 0;

	copy = copy_str(copy, *buffer);
	token = strtok(copy, " ");

	while (token != NULL && sh->num_tokens < 10)
	{
		tokens[sh->num_tokens++] = token;
		token = strtok(NULL, " ");
	}

	for (j = 0; j < sh->num_tokens; j++)
	{
		finArr[j] = tokens[j];
		len = strlen(finArr[j]);

		if (len > 0 && finArr[j][len - 1] == '\n')
		{
			finArr[j][len - 1] = '\0';
		}
	}

	finArr[sh->num_tokens] = NULL;

	return (finArr);
}
/**
 * set_array_cmd - it creates array of str from
 *              enviroment variables.
 * @shell: Pointer to the shell structure.
 * @buffer: a pointer to the string to be modified
 * @size: size of the array.
 * Return: it returns an array of strings.
 */
char **set_array_cmd(shell_var *shell, char **buffer, size_t size)
{
	shell_var *sh = shell;
	char *token = NULL;
	char *tokens[10];
	char *copy = NULL;

	char **finArr = malloc(sizeof(char *) * size);

	int len, j;

	sh->num_tokens = 0;
	copy = copy_str(copy, *buffer);
	token = strtok(copy, ":");

	while (token != NULL && sh->num_tokens < 10)
	{
		tokens[sh->num_tokens++] = token;
		token = strtok(NULL, ":");
	}

	for (j = 0; j < sh->num_tokens; j++)
	{
		finArr[j] = tokens[j];
		len = strlen(finArr[j]);

		if (len > 0 && finArr[j][len - 1] == '\n')
		{
			finArr[j][len - 1] = '\0';
		}
	}

	finArr[sh->num_tokens] = NULL;

	return (finArr);
}
/**
 * array_sort - it sorts an array of str from
 *              shortest to lonhest variables.
 * @arr: a pointer to the string to be sorted
 * @size: size of the array.
 * Return: it returns an array of strings.
 */
void array_sort(char *arr[], int size)
{
	int i, j;
	char *temp;

	for (i = 1; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{

			if (strlen(arr[j]) > strlen(arr[j + 1]))
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
