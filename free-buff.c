#include "main.h"

/**
 * free_buf - frees the buffer
 *
 * @buffer: input
 */
void free_buf(char **buffer)
{
	int i;

	if (buffer == NULL)
		return;

	for (i = 0; buffer[i] != NULL; i++)
	{
		free(buffer[i]);
		buffer[i] = NULL;
	}

	free(buffer);
	buffer = NULL;
}
