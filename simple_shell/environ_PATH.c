#include "shell.h"

/**
 * comp_PATH - a function that compares PATH with environ
 * @str1: pointer PATH string
 * @str2: pointer to environ string
 * Return: 0 (success)
 */

int comp_PATH(const char *str1, const char *str2)
{
	int i;

	for (i = 0; str2[i] != '='; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}

/**
 * spli_PATH - function that counts the number of PATH tokens
 * @string: pointer to string
 * Return: number of PATH tokens
 */

int spli_PATH(char *string)
{
	int i, flag = 1, count = 0;

	for (i = 0; string[i]; i++)
	{

		if (string[i] != ':' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (string[i + 1] == ':')
		{
			flag = 1;
		}
	}
	return (count);
}

/**
 * PATH_concat - concatenate a user string with a PATH token
 * @tmp: pointer to a static array to store the concatenated string
 * @ar: pointer to an array of user strings.
 * @token: pointer to a PATH token
 * Return: 0 (success)
 */

char *PATH_concat(char *tmp, char **ar, char *token)
{
	int length = 0;

	_memset(tmp, 0, 256);
	length = _strlen(token) + _strlen(ar[0]) + 2;
	_strcat(tmp, token);
	_strcat(tmp, "/");
	_strcat(tmp, ar[0]);
	tmp[length - 1] = '\0';
	return (tmp);
}

/**
 * get_environ - gets PATH token from environ
 * @name: pointer to PATH string
 * Return: pointer to PATH string or NULL
 */

char *get_environ(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = comp_PATH(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * _env - prints the environ
 * Return: 0 on success
 */

int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
