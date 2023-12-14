#include"shell.h"

/**
 * display_prompt - to show prompt to the user
 * Return: 0 on sucess
 */

int display_prompt(void)
{
	char *prompt = "shell$ ";
	ssize_t count = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		count = write(STDOUT_FILENO, prompt, 7);
		if (count == -1)
			exit(0);
	}
	return (0);
}

/**
 * read_user_command - reads stdin and stores it in a buffer
 * Return: a pointer to the buffer
 */

char *read_user_command(void)
{
	ssize_t count = 0;
	size_t n;
	int i = 0;
	char *buffer = NULL;

	count = getline(&buffer, &n, stdin);
	if ((count == -1) || _strcmp("exit", buffer) == 0)
	{
		free(buffer);

		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[count - 1] == '\n' || buffer[count - 1] == '\t')
		buffer[count - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}

/**
 * tokenize - creates array of tokens based on user string
 * @buffer: pointer to user string
 * Return: pointer to array of user strings
 */

char **tokenize(char *buffer)
{
	int i = 0;
	int count = 0;
	char *token;
	char **av;
	char *delm = " \n";

	count = _strspl(buffer);
	if (!count)
		return (NULL);
	av = malloc((count + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delm);
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delm);
		i++;
	}
	av[i] = NULL;
	return (av);
}

/**
 * execute - create child process to execute based on user input
 * @argv: pointer to array of user of strings
 * @buffer: pointer to user string
 * @pathbuffer: pointer to user input
 * Return: 0 on success
 */

int execute(char **argv, char *buffer, char *pathbuffer)
{
	pid_t child_pid;
	int i, status, result, logout = 0;

	if (access(pathbuffer, X_OK) != 0)
	{
		perror(argv[0]);
		return (1);
		exit(1);
	} else
	{
		child_pid = fork();
	}
	if (child_pid == -1)
	{
		perror("No such file or directory");
		exit(1);
	}
	if (child_pid == 0)
	{
		result = execve(pathbuffer, argv, environ);
		if (result == -1)
		{
			perror(argv[0]);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(buffer);
			exit(127);
		}
	}
		wait(&status);
	if (WIFEXITED(status))
	{
		logout = WEXITSTATUS(status);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(buffer);
	return (logout);
}
