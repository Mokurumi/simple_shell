#include "main.h"


/**
 * find_executable_path - find executable path
 *
 * @paths: input
 * @command: input
 *
 * Return: char.
 */
char *find_executable_path(char **path, char *command)
{
	int i = 0;
	char *output, *path_command;
	size_t path_len, command_len;

	while (path[i] != NULL)
	{
		path_len = _strlen(path[i]);
		command_len = _strlen(command);

		path_command = malloc(sizeof(char) * (path_len + command_len + 2));
		if (path_command == NULL)
			return (NULL);

		_strcpy(path_command, path[i]);
		if (path_len > 0 && path[i][path_len - 1] != '/')
			_strcat(path_command, "/");

		_strcat(path_command, command);

		if (access(path_command, F_OK | X_OK) == 0)
		{
			output = malloc(sizeof(char) * (_strlen(path_command) + 1));
			if (output == NULL)
			{
				free(path_command);
				return (NULL);
			}
			_strcpy(output, path_command);
			free(path_command);
			return (output);
		}

		free(path_command);
		i++;
	}

	return (NULL);
}
