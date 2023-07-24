#include "main.h"

/**
 * _strcat - check the code
 *
 * @dest: input
 * @src: input
 *
 * Return: char output
 */
char *_strcat(char *dest, char *src)
{
	int i = _strlen(dest);
	int j = 0;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
