#include "shell.h"

/**
 * interpreter - Entry point to handle commands
 * @c: Command
 * Return: Return 0 Success
 */
int interpreter(char *c)
{
	write(STDOUT_FILENO, c, strlen(c));
	write(STDOUT_FILENO, ": No such file or directory\n", 28);

	return (0);
}
/**
 * _env - Entry point to get environment variables
 * @env: Double pointer to variables
 * Return: Return 0 Success
 */
int _env(char **env)
{
	int count = 0;

	while (env[count])
	{
		write(STDOUT_FILENO, env[count], strlen(env[count]));
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}

	return (0);
}
