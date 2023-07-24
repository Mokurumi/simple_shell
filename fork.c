#include "main.h"

/**
 * _fork - fork
 *
 * @command: The command to be executed.
 * @fullCommand: The name of the program.
 *
 * Return: 0 or 1.
 */
int _fork(char *command, char **fullCommand)
{
	pid_t pid;
	int status;

	/* printf("Before fork\n"); */
	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command, fullCommand, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
