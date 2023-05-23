#include "main.h"



/**
 * _setenv - handles the setenv command
 * @args: args
 * Return: none
 */
void _setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
	else if (setenv(args[1], args[2], 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set environment variable\n", 35);
	}
}
/**
 * _unsetenv - handles the unsetenv command
 * @args: args
 * Return: none
 */
void _unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
	}
	else if (unsetenv(args[1]) != 0)
	{
		write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
	}
}

/**
 * cd_command - handles the cd command
 * @args: args
 * Return: none
 */
void cd_command(char **args)
{
	char *dir = args[1];
	char cwd[PATH_MAX], new_cwd[PATH_MAX];

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		dir = getenv("HOME");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		write(STDERR_FILENO, "Failed to get current working directory\n", 40);
		return;
	}
	if (chdir(dir) != 0)
	{
		write(STDERR_FILENO, "Failed to change directory\n", 27);
		return;
	}
	if (setenv("OLDPWD", cwd, 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set OLDPWD environment variable\n", 42);
		return;
	}
	if (getcwd(new_cwd, sizeof(new_cwd)) == NULL)
	{
		write(STDERR_FILENO, "Failed to get current working directory\n", 40);
		return;
	}
	if (setenv("PWD", new_cwd, 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set PWD environment variable\n", 39);
		return;
	}
}
