#include <stdlib.h>
#include <stdio.h>

/**
 * _strconcat - makes a new string by joining together two given strings
 * @str1: first string input
 * @str2: second string input
 *
 * Return: pointer to the newly made string
 */

char *_strconcat(char *str1, char *str2)
{
	int i, x = 0, y = 0;
	static char /***/p[50];

	while (*str1++ != '\0')
		x++;
	while (*str2++ != '\0')
		y++;

	str1 -= (x + 1);
	str2 -= (y + 1);

/*	p = malloc(x + y + 1);

	if (p != NULL)
	{*/
		for (i = 0; i < x; i++)
		{
			p[i] = str1[i];
		}

		for (i = 0; i <= y; i++)
		{
			p[x + i] = str2[i];
		}
	/*}*/
	return (p);
}
