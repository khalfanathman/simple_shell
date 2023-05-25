#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * struct shell_var - Shell variables struct
 * @PROMPT: Prompt flag(true or false)
 * @buf: Buffer pointer
 * @finArr: Array pointer
 * @fin: Pointer to fin
 * @command: Command pointer
 * @comStr: command str from setarr
 * @pathStr: path str from Setcmdarr.
 * @copTok: token frimsetarr;
 * @fpath: path token from setcmdarr
 * @PATH: path to cmd programs
 * @process_id: Process ID
 * @num_tokens: Number of tokens
 * @environs: array of environment variables
 * @getVal: used by getenv;
 * @size: Size of fin array
 * @chRead: number of characters read
 */
typedef struct shell_var
{
	bool PROMPT;
	char *buf;
	char **finArr;
	char **fin;
	char *command;
	char *comStr;
	char *pathStr;
	char *copTok;
	char *fpath;
	char *PATH;
	int process_id;
	int num_tokens;
	char **environs;
	char *getVal;
	size_t size;
	ssize_t chRead;
} shell_var;

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The environment variable to retrieve.
 * @sh:shell variables;
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(char *var, shell_var *sh);

/* DEALING WITH STRINGS 11-3-2023 START */

/**
 * _extract_src - Extract strings from a src
 * @src: The srcing to be extracted_srcized
 * @delim: The delimiter character
 *
 * Return: Pointer to the next extracted_src extracted from 'src',
 *         or NULL if no more extracted_srcs are found.
 */
char *_extract_src(char *src, char *delim);

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
 * int_To_Str - Converts an integer to a string.
 * @str: Pointer to the destination string.
 * @num: The integer to convert.
 */
void int_To_Str(char *str, int num);
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
char *copy_str(char **dest, char *src);

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
void rev_str(char **str);

/**
 * concat_str - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 */
void concat_str(char **dest, char *src);
/**
 * str_to_int - converts str to int status.
 *
 * @str: string to be converted.
 * @pr_id: Process ID number.
 * @prog_name: Name of the program.
 *
 * Return: returns an integer from given str.
 */
int str_to_int(char *str, int pr_id, char *prog_name);
/* DEALING WITH STRINGS END */

/* DEALING WITH ARRAYS 15-3-2023 START */
/**
 * arr_to_int - converts array of ints to single int.
 * @arr: arry to be compressed.
 * @size: size of the arr.
 *
 * Return: the converted in.
 */
int arr_to_int(int *arr, int size);
/**
 * copy_arr - It copies an array of str from
*              stdin
 * @src: a pointer to the string to be modified
 * @len: its the length of the array t be copied
 * @dest: destination fro the array copied
 * Return: it returns an a copy of the array.
 */

void copy_arr(char *dest[], char *src[], int len);
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
/* DEALING WITH STRINGS - dealin with str ***END***  */

/* COMMAND OPERATIONS **START** */

/**
 * check_cmd_exist - Checks if a cmd exists in the PATH environment variable.
 * @shell: Pointer to the shell structure.
 * @term_cm: Command to check.
 * Return: The command if it exists, NULL otherwise.
 */
char *check_cmd_exist(shell_var *shell, char *term_cm);
/**
 * execute_command - Executes a command using execve.
 * @shell: The pointer to struct variables to execute.
 * @fin: The array of command arguments.
 * @envp: The array of environment variables.
 */
void execute_command(shell_var *shell, char **fin, char **envp);
/**
 * set_array_cmd - it creates array of str from
 *              enviroment variables.
 * @shell: Pointer to the shell structure.
 * @buffer: a pointer to the string to be modified
 * @size: size of the array.
 * Return: it returns an array of strings.
 */
char **set_array_cmd(shell_var *shell, char **buffer, size_t size);
/**
 * exiting - converts str to int status.
 * @shell: stract passed to access the array of commands.
 * @prog_name: string to be converted.
 */
void exiting(shell_var *shell, char *prog_name);
/**
 * control_d - Exits a command using CTR + D.
 * @shell: The pointer to struct variables.
 *
 * @envp: The array of environment variables.
 */
void control_d(shell_var *shell, char **envp);
/**
 * sigint_handler - Handles the SIGINT signal.
 * @sig: The signal number.
 */
void sigint_handler(int sig);

/**
 * initialize_shell - Initializes the shell structure.
 * @shell: Pointer to the shell structure.
 * @envp:environmet variable to be saved locally.
 */
void initialize_shell(shell_var *shell, char **envp);
/**
 * _getline - reads string from stdin.
 * @lineptr: The pointer to buffer where the str will be stored.
 * @n: The size of buffer.
 * @strem: The stream to be read from.
 *
 * Return: returns the number of chars read from stdin n -ve if error;
 */
int _getline(char **lineptr, size_t *n, FILE *strem);
/**
 * cleanup - clean up the varable used before next iteration.
 * @shell: Pointer to the shell structure to be cleaned.
 */
void cleanup(shell_var *shell);
/**
 * _setenv - sets environment var to user values
 *
 * @var: variabe to be set
 * @val: value to be set
 * @envp: set of environt variable to search from.
 *
 */
void _setenv(char *var, char *val, char **envp);
/**
 * _unsetenv - removes environment variable
 *
 * @var: variable to be removed.
 * @envp: size of the array that will be used
 *
 */
void _unsetenv(char *var, char **envp);
/**
 * shell_loop - shell prompt to wait for user input
 *
 * @shell: struct variable that can be used through out
 * @size: size of the array that will be used
 * @program_name: program name
 *
 */
void shell_loop(shell_var *shell, size_t size, char *program_name);
/* COMMAND OPERATIONS  ***END*** */

/* DEALING WITH ERRORS ***START** */
void usage_err(char *str);
/**
 * not_found - Handles the "not found" case.
 * @prog: Name of the program.
 * @comd: Command that was not found.
 * @pid_no: Process ID number.
 * @msg: Error message.
 */
void not_found(char *prog, char *comd, int pid_no, char *msg);
/**
 * illegal_no - Handles the "illegal number" case.
 * @prog_name: Name of the program.
 * @pr_id: Process ID number.
 * @msg: Error message.
 * @str: Command that was not found.
 */
void illegal_no(char *prog_name, int pr_id, char *msg, char *str);
/* DEALING WITH ERRORS **END*** */

/**
 * power - calculate power of a number.
 * @base: base of power.
 * @exponent: exponent to be used.
 *
 * Return: return the result of power.
 */
int power(int base, int exponent);

#endif /* MAIN_H */
