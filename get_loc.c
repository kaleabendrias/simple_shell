#include "main.h"

/**
 * get_loc - get full path of command
 * @command: command
 * Return: full path of the command or NULL if not found
 */

char *get_loc(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len, directory_len;
	struct stat buffer;

	if (command == NULL || *command == '\0')
		return (NULL);
	if (stat(command, &buffer) == 0)
	{
		file_path = _strdup(command);
		return (file_path);
	}
	path = getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_len = _strlen(command);
		path_token = _strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_len = _strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			file_path = NULL;
			path_token = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}
