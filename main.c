#include "shell.h"
#define a __attribute__((unused))

/**
 * main - Entry point to shell
 * @argc: pointer to arguments
 * @argv: pointer to argument array
 * @env: environment variable
 * Return: Return 0 Success
 */
int main(a int argc, a char *argv[], char **env)
{
	/*int (*p)(char *, char **, char **);function pointer variable*/
	char **i, *arr, *path, *fpath;
	size_t n;/*Store memory allocated to input*/
	size_t count;
	int f;
	bool running = true;

	n = 0;
	arr = NULL;
	while (running)
	{
		if (isatty(0))
		{
			write(1, "cisfun$ ", 8);
		}
		if (_getline(&arr, &n, stdin) == -1)
		{
			free(arr);
			arr = NULL;
			exit(0);
		}
		f = 0;/*flags for whitespace*/
		for (count = 0; count < strlen(arr); count++)
		{
			if (arr[count] != ' ' || arr[count] != '\n' || arr[count] != '\t')
			{
				f++;
			}
		}
		if (f == 0)
		{
			free(arr);
			arr = NULL;
			continue;
		}
		if (arr[0] == '\n')
		{
			continue;
		}
		if (strcmp(arr, "envp\n") == 0)
		{
			_env(env);
			free(arr);
			arr = NULL;
			continue;
		}
		path = printenv("path", env);
		i = _token(arr, "\n");
		if (strcmp(i[0], "exit") == 0)
		{
			free(arr);
			arr = NULL;
			free(path);
			path = NULL;
			_token_free(i);
			exit(0);
		}
		fpath = c(path, i[0]);
		/*p = r(i, fpath);p(fpath, i, env);*/

		free(fpath);
		fpath = NULL;
		_token_free(i);
		i = NULL;
		free(path);
		path = NULL;
		free(arr);
		arr = NULL;
	}
	return (0);
}
