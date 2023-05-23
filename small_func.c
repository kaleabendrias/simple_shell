#include "main.h"

/**
 * _strchr - searches for characters march
 * @str: the char
 * @character: currentchar
 * Return: Always.
 */

char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *) str);
		}
		str++;
	}
	if (character == '\0')
		return ((char *) str);
	return (NULL);
}

/**
 * _strtok - mimics strtok
 * @str: string
 * @delimiters: delimiter
 * Return: always
 */

char *_strtok(char *str, const char *delimiters)
{
	static char *nextToken, *nextChar;
	unsigned int index;

	if (str != NULL)
		nextChar = str;
	nextToken = nextChar;
	if (nextToken == NULL)
		return (NULL);
	for (index = 0; nextToken[index] != '\0'; index++)
	{
		if (isDelimiter(nextChar[index], delimiters) == 0)
			break;
	}
	if (nextChar[index] == '\0' || nextChar[index] == '#')
	{
		nextChar = NULL;
		return (NULL);
	}
	nextToken = nextChar + index;
	nextChar = nextToken;
	for (index = 0; nextChar[index] != '\0'; index++)
	{
		if (isDelimiter(nextChar[index], delimiters) == 1)
			break;
	}
	if (nextChar[index] == '\0')
		nextChar = NULL;
	else
	{
		nextChar[index] = '\0';
		nextChar = nextChar + index + 1;
		if (*nextChar == '\0')
			nextChar = NULL;
	}
	return (nextToken);
}

/**
 * _strlen - returns the length of string
 * @arg: string
 * Return: always
 */

int _strlen(const char *arg)
{
	int len;

	len = 0;
	while (*arg != '\0')
	{
		len++;
		arg++;
	}
	return (len);
}

/**
 * _strcpy - main
 * @dest: destination
 * @src: source
 * Return: none
 */

void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strcat - does function of strcat
 * @dest: destination
 * @src: source
 * Return: none
 */

void _strcat(char *dest, const char *src)
{
	int dest_len, i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}
