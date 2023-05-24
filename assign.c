#include "shell.h"

/**
 * _token - Entry point to string tokenizing
 * @s: P{ointer to the string
 * @del: Pointer to delimiter
 * Return: Return tokenized string Success
 */
char **_token(char *s, char *del)
{
	char **ts, *str, *t;
	int count;

	ts = NULL;
	count = 0;
	str = malloc(strlen(s) + 1);/*+1 for null terminator*/
	if (str == NULL)
	{
		return (NULL);
	}
	str = strcpy(str, s);
	t = strtok(str, del);
	while (t != NULL)
	{
		count++;
		ts = realloc(ts, (count + 1) * sizeof(*ts));
		if (ts == NULL)
		{
			free(str);
			return (NULL);
		}
		ts[count - 1] = t;
		t = strtok(NULL, del);
	}
	ts[count] = NULL;
	free(str);
	return (ts);
}
/**
 * _token_free - Entry point to free token
 * @tok: Double pointer of freed string
 */
void _token_free(char **tok)
{
	if (tok == NULL)
	{
		return;
	}
	free(tok[0]);
	free(tok);
}
