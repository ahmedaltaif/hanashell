#include "shell.h"
/**
 * PATH_buffer - finds the string to call execve on
 * @ar: pointer to array
 * @dup: duplicate pointer of PATH string
 * @PATH: pointer to PATH string
 * Return: a pointer to string to call execve on
 */

char *PATH_buffer(char **ar, char *PATH, char *dup)
{
	char *tok, *buffer = NULL, *strcomp = NULL;
	static char tmp[256];
	int count = 0, path_flag = 0, i = 0, tokenlength = 0;
	struct stat h;

	dup = NULL;
	dup = _strdup(PATH);
	count = spli_PATH(dup);
	tok = strtok(dup, ": =");
	if (PATH == NULL)
		PATH = "/usr/bin:/bin:/usr/sbin:/sbin";
	while (tok != NULL)
	{
		strcomp = PATH_concat(tmp, ar, tok);
		if (stat(strcomp, &h) == 0)
		{
			buffer = strcomp;
			path_flag = 1;
			break;
		}
		if (i < count - 2)
		{
			tokenlength = _strlen(tok);
			if (tok[tokenlength + 1] == ':')
			{
				if (stat(ar[0], &h) == 0)
				{
					buffer = ar[0];
					path_flag = 1;
					break;
				}
			}
		}
		i++;
		tok = strtok(NULL, ":");
	}
	if (path_flag == 0)
		buffer = ar[0];
	free(dup);
	return (buffer);
}
