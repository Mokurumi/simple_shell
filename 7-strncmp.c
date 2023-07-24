#include "main.h"

/**
 * _strncmp - compare chars in str 1 & 2 to the specified length.
 *
 * @str1: input
 * @str2: input
 * @n: input
 *
 * Return: int
 *
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		else if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
