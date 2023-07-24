#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _getenv - Get the value of an environment variable.
 *
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(const char *name)
{
	char *env_var;

	if (name == NULL)
		return (NULL);

	env_var = getenv(name);

	if (env_var == NULL)
		return (NULL);

	return (_strdup(env_var));
}
