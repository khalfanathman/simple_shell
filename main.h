#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * struct shell_var - Shell variables struct
 * @PROMPT: Prompt flag
 * @buf: Buffer pointer
 * @finArr: Array pointer
 * @fin: Pointer to fin
 * @command: Command pointer
 * @process_id: Process ID
 * @num_tokens: Number of tokens
 * @size: Size
 * @chRead: Read size
 */
typedef struct shell_var
{
	bool PROMPT;
	char *buf;
	char **finArr;
	char **fin;
	char *command;
	int process_id;
	int num_tokens;
	size_t size;
	ssize_t chRead;
} shell_var;
/**
 * check_cmd_exist - Checks if a cmd exists in the PATH environment variable.
 * @shell: Pointer to the shell structure.
 * @term_cm: Command to check.
 *
 * Return: The command if it exists, NULL otherwise.
 */
char *check_cmd_exist(shell_var *shell, char *term_cm);

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The environment variable to retrieve.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(char *var);

/* DEALING WITH STRINGS 11-3-2023 START */

/**
 * _strtok - Extract tokens from a string.
 * @str: The string to be tokenized.
 * @delim: The delimiter character.
 *
 * Return: Pointer to the next token extracted from 'str',
 *         or NULL if no more tokens are found.
 */
char *_strtok(char *str, char *delim);

/**
 * _strlen - Calculate the length of a null-terminated string.
 * @line: The input string.
 *
 * Return: The length of the string (excluding the null terminator).
 */
size_t _strlen(char *line);

/**
 * _strchr - Locate first occurrence of a character in a string.
 * @line: The string to search within.
 * @letter: The character to locate.
 *
 * Return: Pointer to the first occurrence of the char 'c' in the string 'str',
 *         or NULL if the character is not found.
 */
char *_strchr(char *line, int letter);

/**
 * compare_str - Checks if two strs are equal.
 * @str1: String 1 to be passed.
 * @str2: String 2 to be passed for checking.
 *
 * Return: Returns -1 if they don't match and 0 if they are equal.
 */
int compare_str(char *str1, char *str2);

/**
 * copy_str - It copies an array of str from user stdin.
 * @src: A pointer to the string to be copied.
 * @dest: A pointer to the string to be modified
 * Return: It returns a copy of the array.
 */
char *copy_str(char *dest, char *src);

/**
 * compare_str_long - Compares two strings and returns the shorter one.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: Pointer to the shorter string.
 */
char *compare_str_long(char *str1, char *str2);

/**
 * _puts - Prints a string to stdout.
 * @str: The string to be printed.
 */
void _puts(char *str);

/**
 * rev_str - Reverses a string in-place.
 * @str: The string to be reversed.
 */
void rev_str(char *str);

/**
 * concat_str - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the concatenated string.
 */
char *concat_str(char **dest, char *src);

/**
 * not_found - Handles the "not found" case.
 * @prog: Name of the program.
 * @comd: Command that was not found.
 * @pid_no: Process ID number.
 * @msg: Error message.
 */
void not_found(char *prog, char *comd, int pid_no, char *msg);

/* DEALING WITH STRINGS END */

/* DEALING WITH ARRAYS 15-3-2023 START */

/**
 * copy_arr - It copies an array of str from
*              stdin
 * @src: a pointer to the string to be modified
 * @len: its the length of the array t be copied
 * Return: it returns an a copy of the array.
 */

char **copy_arr(char ***src, int *len);
/**
 * setArray - it creates array of str from user
 *              stdin
 * @shell: Pointer to the shell structure.
 * @buffer: a pointer to the string to be modified
 * @size: the size of array
 * Return: it returns an array of strings.
 */
char **setArray(shell_var *shell, char **buffer, size_t size);

/**
 * array_sort - Sorts an array of strings in lexicographical order.
 * @arr: The array of strings to be sorted.
 * @size: The size of the array.
 */
void array_sort(char *arr[], int size);
/**
 * print_env - Prints the elements of an environment variable array.
 * @env: The array of environment variable strings.
 */
void print_env(char **env);
/**
 * set_array_cmd - Sets an array of strings by tokenizing a buffer.
 * @shell: Pointer to the shell structure.
 * @buffer: Pointer to the buffer to be tokenized.
 * @size: The size of the array.
 *
 * Return: Pointer to the array of strings.
 */
char **set_array_cmd(shell_var *shell, char **buffer, size_t size);

/* DEALING WITH STRINGS - dealin with str SEND  */


/**
 * execute_command - Executes a command using execve.
 * @shell: The pointer to struct variables to execute.
 * @fin: The array of command arguments.
 * @envp: The array of environment variables.
 */
void execute_command(shell_var *shell, char **fin, char **envp);
/**
 * sigint_handler - Handles the SIGINT signal.
 * @sig: The signal number.
 */
void sigint_handler(int sig);

/**
 * initialize_shell - Initializes the shell structure.
 * @shell: Pointer to the shell structure.
 */
void initialize_shell(shell_var *shell);
#endif /* MAIN_H */
