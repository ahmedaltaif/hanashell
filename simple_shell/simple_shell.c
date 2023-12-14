#include "shell.h"
/**
 * main - entry point that is runing the shell
 * Return: 0 on success
 */
int main(void)
{

	char *pathbuffer = NULL;
	char *cp = NULL;
	char *buffer = NULL;
	char *PATH = NULL;
	char **av;
	int logout = 0;

	PATH = get_environ("PATH");
	if (PATH == NULL)
		return (-1);
	while (true)
	{
		av = NULL;
		display_prompt();
		buffer = read_user_command();
		if (*buffer != '\0')
		{
			av = tokenize(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			pathbuffer = PATH_buffer(av, PATH, cp);
			if (_built_in(av, buffer, logout) == 1)
				continue;
			logout = execute(av, buffer, pathbuffer);
		}
		else
		free(buffer);


	}
	return (0);
}
