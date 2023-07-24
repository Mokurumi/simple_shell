#include "main.h"

/**
 * _getline - Read a line from a file stream.
 *
 * @lineptr: Pointer to the buffer where the line is stored.
 * @n: Pointer to the variable that holds the size of the buffer.
 * @stream: The input file stream.
 *
 * Return: The number of characters read, or -1 on failure or end of file.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL, *new_line;
	size_t size = 0;
	int c;
	ssize_t num_chars = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	/* Read characters until end of line or end of file */
	while ((c = fgetc(stream)) != EOF)
	{
		/* Increase buffer size if necessary */
		if ((size_t)num_chars >= size)
		{
			size += 128;
			new_line = realloc(line, size);
			if (new_line == NULL)
			{
				free(line);
				return (-1);
			}
			line = new_line;
		}
		line[num_chars++] = (char)c;

		/* Check for end of line */
		if (c == '\n')
			break;
	}

	if (num_chars == 0)
		return (-1);

	line[num_chars] = '\0';
	*lineptr = line;
	*n = size;

	return (num_chars);
}
