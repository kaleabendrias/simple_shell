#include "main.h"


/**
 * tokenize_input - tokenizes the commands
 * @input: the total comm
 * @args: args
 * Return: Always
 */

int tokenize_input(char *input, char **args)
{
	int argc;
	char *token;

	argc = 0;
	token = _strtok(input, " \t\n");
	while ((token != NULL) & (argc < MAX_ARGS - 1))
	{
		if (token[0] != '#')
			args[argc++] = token;
		token = _strtok(NULL, " \t\n");
	}
	args[argc] = NULL;
	return (argc);
}

/**
 * handle_signal - handles signals
 * @signal: signal
 * Return: none
 */

void handle_signal(int signal)
{
	(void)signal;
	/*write(STDOUT_FILENO, "\n$ ", 3);*/
}

/**
 * main - entry point
 * @argc: arguments
 * @argv: pointers
 * Return: Always
 */

int main(int argc, char *argv[])
{
	char *getcom = NULL;
	size_t n = 0;
	ssize_t n_char;
	char *args[MAX_ARGS];
	(void)argv;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		n_char = getline(&getcom, &n, stdin);
		if (n_char == -1)
			break;
		argc = tokenize_input(getcom, args);
		if (argc > 0)
		{
			signal(SIGINT, handle_signal);
			exe(args);
		}
	}
	free(getcom);
	return (0);
}

