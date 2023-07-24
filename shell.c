#include "main.h"

/**
 * print_prompt - Print the shell prompt
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * read_command - Read the user input and tokenize it
 *
 * Return: A tokenized command
 */
char **read_command(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linesize = getline(&line, &bufsize, stdin);
	char **command;

	if (linesize < 0)
	{
		free(line);
		return (NULL);
	}

	if (line[linesize - 1] == '\n')
		line[linesize - 1] = '\0';

	command = tokenize(line);
	free(line);

	return (command);
}

/**
 * execute_command - Execute the given command
 *
 * @command: The command to execute
 * @av: args array
 */
void execute_command(char **command, char **av)
{
	char *path, **paths, *pathcommand;

	if (command == NULL || *command == NULL || **command == '\0')
		return;

	if (handle_command(command, command[0]))
		return;

	path = find_path();
	paths = tokenize(path);
	pathcommand = find_executable_path(paths, command[0]);

	if (!pathcommand)
		perror(av[0]);
	else
		_fork(pathcommand, command);

	free_buf(paths);
	free(pathcommand);
}

/**
 * run_shell - The main loop to run the shell
 *
 * @av: args array
 */
void run_shell(char **av)
{
	int interactive = 0;
	char **command;

	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		interactive = 1;

	signal(SIGINT, handle_signal);

	print_prompt();

	while (1)
	{
		command = read_command();

		if (command == NULL)
			break;

		execute_command(command, av);
		free_buf(command);

		if (interactive)
			print_prompt();
	}

	if (interactive)
		write(STDERR_FILENO, "\n", 1);
}

/**
 * main - check the code
 *
 * @ac: args length
 * @av: args array
 * @env: environment
 *
 * Return: 0 or 1
 */
int main(int ac, char **av, char *env[])
{
	(void)env, (void)av;

	if (ac < 1)
		return (-1);

	run_shell(av);

	return (0);
}
