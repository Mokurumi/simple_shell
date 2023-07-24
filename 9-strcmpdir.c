#include "main.h"

/**
 * _strcmpdir - compares two directory paths
 *
 * @str1: input
 * @str2: input
 *
 * Return: int
 */
int _strcmpdir(const char *str1, const char *str2)
{
	if (str1 == NULL && str2 == NULL)
		return (0);
	else if (str1 == NULL)
		return (-1);
	else if (str2 == NULL)
		return (1);

	while (*str1 && *str2)
	{
		if (*str1 == '/' && *str2 == '/')
		{
			/* Skip consecutive slashes */
			while (*str1 == '/')
				str1++;
			while (*str2 == '/')
				str2++;
		}
		else if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		else
		{
			str1++;
			str2++;
		}
	}

	if (*str1 == '/' && *str2 == '/')
	{
		/* Skip trailing slashes */
		while (*str1 == '/')
			str1++;
		while (*str2 == '/')
			str2++;
	}

	return (*str1 - *str2);
}
