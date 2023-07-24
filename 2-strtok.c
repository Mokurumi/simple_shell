#include "main.h"

/**
 * _strtok - Tokenizes a string by delimiter
 *
 * @str: The input string to be tokenized
 * @delim: The delimiter string
 *
 * Return: Pointer to the next token, or NULL if there are no more tokens
 */
char *_strtok(char *str, char *delim)
{
	static char *token;
	size_t token_len;
	char *result, *delim_ptr;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);

	token_len = _strlen(token);
	result = token;

	if (token_len == 0)
	{
		token = NULL;
		return (NULL);
	}

	delim_ptr = _strpbrk(token, delim);

	if (delim_ptr)
	{
		*delim_ptr = '\0';
		token = delim_ptr + 1;
	}
	else
		token = NULL;

	return (result);
}
