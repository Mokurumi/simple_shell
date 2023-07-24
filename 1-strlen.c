#include "main.h"

/**
 * _strlen - gets the length of a string
 *
 * @s: input
 *
 * Return: output
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
