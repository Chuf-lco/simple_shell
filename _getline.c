#include "shell.h"

/**
 * _getline - Entry point to getline function
 * @lineptr: Pointer to input
 * @n: Pointer to size of buffer
 * @stream: Buffer read
 * Return: Return read bytes success
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesR;
	size_t buffer = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL || *n == 0)
	{
		buffer = 256;
		*lineptr = (char *)malloc(buffer * sizeof(char));
		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = buffer;
	}
	bytesR = getline(lineptr, n, stream);
	if (bytesR == -1)
	{
		free(*lineptr);
		*lineptr = NULL;
		*n = 0;
	}
	return (bytesR);
}
