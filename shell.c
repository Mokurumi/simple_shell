#include"main.h"

/**
 * main - check the code
 *
 * @ac: args length
 * @av: args array
 * @env: envrionment
 *
 * Return: 0 or 1
 */
int main(int ac, char **av, char *env[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	int interactive = 0;

	(void)env, (void)av;

	if (ac < 1)
		return (-1);

	signal(SIGINT, handle_signal);

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		interactive = 1;
	if (interactive)
		write(STDERR_FILENO, "$ ", 2);

	while (1)
	{
		free_buf(command);
		free_buf(paths);
		free(pathcommand);

		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;

		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';

		command = tokenize(line);

		if (command == NULL || *command == NULL || **command == '\0')
			continue;

		if (handle_command(command, line))
			continue;

		path = find_path();
		paths = tokenize(path);
		pathcommand = find_executable_path(paths, command[0]);

		if (!pathcommand)
			perror(av[0]);
		else
			_fork(pathcommand, command);
	}

	if (linesize < 0 && interactive)
		write(STDERR_FILENO, "\n", 1);

	free(line);
	return (0);
}
