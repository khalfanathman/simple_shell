#include "main.h"
/**
 * copy_arr - it copies an array of str from user
 *              stdin
 * @src: a pointer to the arry of strings to be modified
 * @len: its the length of the array t be copied
 * @dest: destination fro the array copied
 * Return: it returns an a copy of the array.
 */
void copy_arr(char *dest[], char *src[], int len)
{
	int i = 0;

	for (i = 0; i < len - 1 ; i++)
	{
		copy_str(&dest[i], src[i]);
	}

	/* dest[len] = NULL; */
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
	char **tokens = malloc(sizeof(char *) * size);
	char *copy = malloc(_strlen(*buffer) + 1);
	int len = 0, j = 0;

	sh->fin = malloc(sizeof(char *) * size);

	sh->num_tokens = 0;

	copy_str(&copy, *buffer);
	token = strtok(copy, " ");

	while (token != NULL && sh->num_tokens < 10)
	{
		tokens[sh->num_tokens++] = token;
		token = strtok(NULL, " ");
	}

	for (j = 0; j < sh->num_tokens; j++)
	{
		sh->fin[j] = tokens[j];
		len = _strlen(sh->fin[j]);

		if (len > 0 && sh->fin[j][len - 1] == '\n')
		{
			sh->fin[j][len - 1] = '\0';
		}
	}
	sh->fin[sh->num_tokens] = NULL;
	free(tokens);
	sh->comStr = copy;
	/* free(copy); */
	return (sh->fin);
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
	char **tokens = malloc(sizeof(char *) * size);
	char *copy = malloc(strlen(*buffer) + 1);
	int len, j;

	shell->finArr = malloc(sizeof(char *) * size);


	sh->num_tokens = 0;
	copy_str(&copy, *buffer);
	token = strtok(copy, ":");

	while (token != NULL && sh->num_tokens < 10)
	{
		tokens[sh->num_tokens++] = token;
		token = strtok(NULL, ":");
	}

	for (j = 0; j < sh->num_tokens; j++)
	{
		shell->finArr[j] = tokens[j];
		len = _strlen(shell->finArr[j]);

		if (len > 0 && shell->finArr[j][len - 1] == '\n')
		{
			shell->finArr[j][len - 1] = '\0';
		}
	}

	shell->finArr[sh->num_tokens] = NULL;
	free(tokens);
	sh->pathStr = copy;
	return (shell->finArr);
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

/**
 * arr_to_int - converts array of ints to single int.
 * @arr: arry to be compressed.
 * @size: size of the arr.
 *
 * Return: the converted in.
 */
int arr_to_int(int *arr, int size)
{
	static int i;

	if ((1 << size) == 1)
	{
		return (0);
	}
return ((power(10, size - 1) * arr[i++]) + arr_to_int(arr, (size - 1)));
}
