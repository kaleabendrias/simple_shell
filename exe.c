#include "main.h"

/**
 * env_ex - ex
 * Return: none
 */

void env_ex(void)
{
	char **env, *env_line;
	size_t env_len;

	env = environ;
	while (*env != NULL)
	{
		env_line = *env;
		env_len = _strlen(env_line);
		write(STDOUT_FILENO, env_line, env_len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * execute_command - executes commands
 * @actual_command: full path command
 * @args: args
 * @command: the command
 * Return: none
 */

void execute_command(char *actual_command, char **args, char *command)
{
	pid_t pid;
	char *envp[] = { NULL };
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(actual_command, args, envp) == -1)
		{
			perror(args[0]);
			free(command);
			free(actual_command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror(args[0]);
	else
	{
		waitpid(pid, &status, 0);
	}
	free(actual_command);
}

/**
 * handle_command - handles the command before passing it to exec
 * @command: command
 * @args: args
 * Return: none
 */

void handle_command(char *command, char **args)
{
	char *actual_command;
	int status;

	if (_strcmp(command, "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
			free(command);
			exit(status);
		}
		else
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
	}
	else if (_strcmp(command, "env") == 0)
		env_ex();
	else if (_strcmp(command, "setenv") == 0)
		_setenv(args);
	else if (_strcmp(command, "unsetenv") == 0)
		_unsetenv(args);
	else if (_strcmp(command, "cd") == 0)
		cd_command(args);
	else
	{
		actual_command = get_loc(command);
		if (!actual_command)
			write(STDOUT_FILENO, "Error: Command not found\n", 25);
		else if (access(actual_command, X_OK) == -1)
		{
			free(actual_command);
			write(STDOUT_FILENO, "Error: No such file or directory\n", 33);
		}
		else
			execute_command(actual_command, args, command);
	}
}

/**
 * exe - main
 * @args: args
 * Return: none
 */

void exe(char **args)
{
	char *command;

	command = args[0];
	handle_command(command, args);
}
