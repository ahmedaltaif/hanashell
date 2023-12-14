#include "shell.h"

/**
 * _strcmp - a function that compares two strings
 * @str1: char type
 * @str2: char type
 * Return: integer value
 */

int _strcmp(const char *str1, const char *str2)
{
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 - *str2);
}

/**
 * _strdup - a function is used to duplicates a string
 * @string: pointer to string.
 * Return: a pointer to a new string that is a duplicate
 */

char *_strdup(char *string)
{
	int i;
	char *dest;

	if (string == NULL)
		return (NULL);
	for (i = 0; string[i] != '\0'; i++)
		;
	dest = malloc(sizeof(char) * (i + 1));

	if (dest == NULL)
		return (NULL);
	for (i = 0; string[i] != '\0'; i++)
	{
		dest[i] = string[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strspl - a function that counts number of words in string
 * @string: pointer to string
 * Return: number of words
 */

int _strspl(char *string)
{
	int i;
	int flag = 1;
	int count = 0;

	for (i = 0; string[i]; i++)
	{
		if (string[i] != ' ' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (string[i + 1] == ' ')
			flag = 1;
	}
	return (count);
}

/**
 * _strlen - a function that used to calculate the length of a string
 * @str: pointer to string
 * Return: integer
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _strcat - a function is used to concatenate two strings
 * @dest: the first string
 * @con: the second string
 * Return: a pointer to the first string after the combining
 */

char *_strcat(char *dest, char *con)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; con[j] != '\0'; j++, i++)
		dest[i] = con[j];
	dest[i] = '\0';
	return (dest);
}
