#include "main.h"

/**
 * find_path - find path
 *
 * Return: char
 */
char *find_path(void)
{
	char **env = environ;
	const char *prefix = "PATH=";

	while (*env)
	{
		if (_strncmp(*env, prefix, strlen(prefix)) == 0)
		{
			return (*env + strlen(prefix));
		}
		env++;
	}

	return (NULL);
}
