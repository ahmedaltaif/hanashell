#include "shell.h"
/**
 * _built_in - function that check if first user string is a built-in
 * @ar: pointer to array
 * @buf: pointer to user string
 * @logout: exit status
 * Return: 1 if user string is equal to env or 0 otherwise
 */
int _built_in(char **ar, char *buf, int logout)
{
	int i, status;

	if (_strcmp(ar[0], "env") == 0)
	{
		_env();
		for (i = 0; ar[i]; i++)
			free(ar[i]);
		free(ar);
		free(buf);
		return (1);
	} else if (_strcmp(ar[0], "exit") == 0)
	{
		status = logout;
		if (ar[1] != NULL)
			status = atoi(ar[1]);
		fflush(stdout);
		for (i = 0; ar[i]; i++)
			free(ar[i]);
		free(ar);
		free(buf);
		exit(status);
	} else if (_strcmp(ar[0], "cd") == 0)
	{
		char dir[120];

		if (ar[1] == NULL)
		{
			status = chdir(getcwd(dir, sizeof(dir)));
				return (1);
		} else
		{
			status = chdir(ar[1]);
			return (1);
		}
		if (status != 0)
		return (1);
	}
	else
		return (0);

}
