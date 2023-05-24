#include "shell.h"

/**
 * _exec - Entry point to execute function
 * @i: Command arguments
 * @fpath: File name
 * @env: Environment variables
 * Return: Return 0 Success
 */
int _exec(char **i, char *fpath, char **env)
{
	int stval = fork(), exstat;

	if (stval == 0)
	{
		execve(fpath, i, env);
	}
	else if (stval > 0)/*parent process*/
	{
		wait(&exstat);
	}
	return (0);
}
