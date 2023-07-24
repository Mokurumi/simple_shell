#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 *
 * @s: input
 * @accept: input
 *
 * Return: char
 *
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *temp = accept;

		while (*temp != '\0')
		{
			if (*s == *temp)
			{
				return (s);
			}

			temp++;
		}

		s++;
	}

	return (NULL);
}
