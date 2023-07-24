#include "main.h"

/**
 * env_environ - check the code
 *
 * @argc: args length
 * @argv: args array
 * @env: environment
 *
 * Return: output
 */
int env_environ(int argc, char *argv[], char *env[])
{
	char **environ = env;
	int i;
	uintptr_t env_address, environ_address;

	/* Access command-line arguments */
	printf("Number of arguments: %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}

	env_address = (uintptr_t)env;
	environ_address = (uintptr_t)environ;

	printf("Address of env: %p\n", (void *)env_address);
	printf("Address of environ: %p\n", (void *)environ_address);

	return (0);
}
