#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 *
 * @str: string to be duplicated
 *
 * Return: a pointer to the duplicated string, or NULL if str is NULL
 */
char *_strdup(char *str)
{
	size_t len;
	char *dup;

	if (str == NULL) /* check for NULL string */
	{
		return (NULL);
	}

	/* get length of string including null terminator */
	len = strlen(str) + 1;
	 /* allocate memory for duplicated string */
	dup = malloc(len * sizeof(char));

	if (dup == NULL) /* check for allocation failure */
	{
		return (NULL);
	}

	strcpy(dup, str); /* copy original string to duplicated string */
	return (dup); /* return pointer to duplicated string */
}
