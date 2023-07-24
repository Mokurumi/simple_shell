#include "main.h"

/**
 * _strcpy - check the code
 *
 * @dest: input
 * @src: input
 *
 * Return: char output
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (start);
}
