#include "main.h"

/**
 * _setenv - set or modify an environment variable
 * @args: array of user input
 * Return: 1 on success, -1 on failure
 */
int _setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (1);
}

/**
 * _unsetenv - remove an environment variable
 * @args: array of user input
 * Return: 1 on success, -1 on failure
 */
int _unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (1);
}

/**
 * execute_builtin - execute a builtin command
 * @args: array of user input
 * Return: 1 if the command is a builtin, 0 otherwise
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		return (_setenv(args));
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		return (_unsetenv(args));
	}

	return (0);
}
