#include "main.h"

/**
 * env_main - prints the environment
 *
 * @env: envrionment
 *
 * Return: Always 0.
 */
int env_main(void)
{
	unsigned int i;
	char **env = environ;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
