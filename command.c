#include "shell.h"
/**
 * command - Entry point for command
 * @p: Pointer to string for environmnet variable
 * @arr: Pointer to name of variable
 * Return: Return name Success
 */
char *c(char *p, char *arr)
{
	char **a;
	int count;
	char *c, *t;
	size_t arrLen, tLen, maxCLen, aLen, cLen;
	struct stat info;

	if (stat(arr, &info) == 0)
	{
		c = malloc(strlen(arr) + 1);
		c = strcpy(c, arr);
		return (c);
	}
	a = _token(p, ":");
	arrLen = strlen(arr);
	tLen = arrLen + 2;
	t = malloc(tLen);
	t = strcpy(t, "/");
	t = strcat(t, arr);
	t[tLen - 1] = '\0';
	maxCLen = 0;
	for (count = 0; a[count] != NULL; count++)
	{
		aLen = strlen(a[count]);
		cLen = aLen + tLen;
		if (cLen > maxCLen)
		{
			maxCLen = cLen;
		}
	}
	c = malloc(maxCLen);
	for (count = 0; a[count] != NULL; count++)
	{
		c = strcpy(c, a[count]);
		c = strcat(c, t);
		if (stat(c, &info) == 0)
		{
			free(t);
			_token_free(a);
			return (c);
		}
	}
	free(t);
	_token_free(a);
	c = strcpy(c, arr);
	return (c);
}
