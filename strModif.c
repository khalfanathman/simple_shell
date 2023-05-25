#include "main.h"

/**
 * rev_str - Reverse the str of string
 * @str: The pointer input string to be reversed
 *
 * Return: does not return;
 */
void rev_str(char **str)
{
	int len = 0, i = 0;
	char *str1;
	char *tem;

	len = _strlen(*str);
	str1 = malloc(sizeof(char) * len);
	tem = malloc(sizeof(char) * len);
	copy_str(&str1, *str);

	while (i < len - 1)
	{
		tem[i] = str1[len - i];
		i++;
	}

	copy_str(str, tem);
	free(str1);
	free(tem);
}
/**
 * concat_str - concatenates the src to dest
 * @dest: The input string to be concatenated to
 * @src: The input string to be concatenated from
 */
void concat_str(char **dest, char *src)
{
	size_t dest_len = _strlen(*dest);
	size_t src_len = _strlen(src);
	size_t total_len = dest_len + src_len + 1;
	char *newArr = malloc(sizeof(char) * total_len);
	size_t i, j = 0;

	for (i = 0; i < dest_len; i++)
	{
		newArr[i] = (*dest)[i];
	}

	for (; src[j] != '\0'; j++, i++)
	{
		newArr[i] = src[j];
	}

	newArr[i] = '\0';
	free(*dest);
	*dest = newArr;
}

/**
 * str_to_int - converts str to int status.
 * @str: string to be converted.
 * @pr_id: Process ID number.
 * @prog_name: Name of the program.
 *
 * Return: returns an integer from given str.
 */
int str_to_int(char *str, int pr_id, char *prog_name)
{
	int i = 0, state, size;
	int *status = malloc(sizeof(char) * 10);

	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			illegal_no(prog_name, pr_id, "illegal number", str);
			return (-1);
		}

		status[i] = str[i] - '0';
		i++;
	}

	size = i;
	state = arr_to_int(status, size);
	free(status);
	return (state);
}
