#include "main.h"


/**
 * _realloc - Reallocates a memory block
 * @ptr: A pointer to  previously allocated memory.
 * @old_size: @size ptr.
 * @new_size: the new memory block size.
 * Return: @new_size | NULL
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *memory;
	char *src, *dest;
	size_t copy_size, i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	memory = malloc(new_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr != NULL)
	{
		src = ptr;
		dest = memory;
		copy_size = old_size < new_size ? old_size : new_size;
		for (i = 0; i < copy_size; i++)
			dest[i] = src[i];
		free(ptr);
	}
	return (memory);
}

/**
 * _lineptr - Reassigns the lineptr.
 * @lineptr: A buffer to store.
 * @size_l: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @size_b: The size of buffer.
 */

void _lineptr(char **lineptr, size_t *size_l, char *buffer, size_t size_b)
{
	size_t new_size = BUFFER_SIZE;

	if (*lineptr == NULL || *size_l < size_b)
	{
		if (size_b > BUFFER_SIZE)
			new_size = size_b;
		*size_l = new_size;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}


/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t rid;
	char c = 'A', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == EOF || (r == '\0' && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == '\0' && input != 0)
		{
			input++;
			break;
		}

		if (input >= BUFFER_SIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	_lineptr(lineptr, n, buffer, input);
	rid = input;
	if (r != EOF)
		input = 0;
	return (rid);
}
