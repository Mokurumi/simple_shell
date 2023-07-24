#include "main.h"

/**
 * cd_builtin - Changes the current directory of the process.
 *
 * @command: Tokenized command containing directory argument.
 *
 * Return: Always returns 1.
 */
int cd_builtin(char **command)
{
	char cwd[PATH_MAX];
	char *dir = command[1];

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		dir = getenv("HOME");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
		printf("%s\n", dir);
	}

	if (chdir(dir) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("PWD", cwd, 1);
			setenv("OLDPWD", getenv("PWD"), 1);
		}
		else
		{
			perror("getcwd() error");
		}
	}
	else
	{
		perror("chdir() error");
	}
	return (1);
}
