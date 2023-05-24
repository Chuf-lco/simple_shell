#include "shell.h"
/**
 * printenv - Get value of string from  environment
 * @a: Variable name
 * @env: Inherited environment
 * Return: Return pointer Success
 */

char *printenv(char *a, char **env)
{
	char **b, *c;/*b-tokenize environment variable & c-store value*/
	int count = 0;

	while (env[count] != NULL)
	{
		b = _token(env[count], "=");/*=delimiter  splits the variable*/
		if (strcmp(b[0], a) == 0)
		{
			c = malloc(strlen(b[1]) + 1);
			c = strcpy(c, b[1]);

			_token_free(b);
			return (c);
		}
		_token_free(b);
		count++;
	}
	return (NULL);
}
