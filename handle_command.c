#include "main.h"

/**
 * handle_command - do check
 *
 * @command: tokenized commands
 * @line: input read from stdin
 *
 * Return: 0 or 1
 *
 */
int handle_command(char **command, char *line)
{
	char *builtin_commands[] = {"env", "cd", "setenv", "unsetenv", "exit"};

	if (_strcmp(*command, builtin_commands[0]) == 0)
	{
		env_main();
		return (1);
	}
	else if (_strcmp(*command, builtin_commands[1]) == 0)
	{
		return (cd_builtin(command));
	}
	else if (_strcmp(*command, builtin_commands[2]) == 0)
	{
		return (_setenv(command));
	}
	else if (_strcmp(*command, builtin_commands[3]) == 0)
	{
		return (_unsetenv(command));
	}
	else if (_strcmp(*command, builtin_commands[4]) == 0)
	{
		if (command[1] != NULL)
		{
			int status = atoi(command[1]);

			free(line);
			free_buf(command);
			exit(status);
		}
		else
		{
			free(line);
			free_buf(command);
			exit(0);
		}
	}
	else if (**command == '/')
	{
		_fork(command[0], command);
		return (1);
	}
	return (0);
}
