#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * my_getline - Reads a line of input from stdin
 *
 * This function reads input from the standard input until a newline character
 * is encountered or the buffer is full. It dynamically allocates memory for
 * the input line and returns a pointer to it.
 *
 * Return: Pointer to the input line, or NULL on failure or end of input
 */
char *my_getline(void)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int buffer_size = 0;
	char *line = NULL;
	int line_size = 0;
	int line_index = 0;

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				break;
			buffer_index = 0;
		}

		int i;

		for (i = buffer_index; i < buffer_size; i++)
		{
			if (buffer[i] == '\n')
				break;
		}

		int line_length = line_index + (i - buffer_index);

		if (line_length >= line_size)
		{
			line_size = line_length + 1;
			char *new_line = realloc(line, line_size);

			if (new_line == NULL)
			{
				perror("realloc");
				free(line);
				exit(EXIT_FAILURE);
			}
			line = new_line;
		}

		for (; buffer_index < i; buffer_index++, line_index++)
		{
			line[line_index] = buffer[buffer_index];
		}

		if (i < buffer_size)
		{
			line[line_index] = '\0';
			buffer_index++;
			return (line);
		}
	}

	if (line != NULL)
	{
		line[line_index] = '\0';
	}
	return (line);
}

/**
 * main - Entry point of the program
 *
 * This function serves as the entry point of the program. It calls the
 * `my_custom_main` function, which contains the main logic of the shell.
 * After `my_custom_main` completes, the program returns 0 to indicate
 * successful execution.
 *
 * Return: 0 on successful completion
 */
int main(void)
{
	char *line = my_getline();

	printf("Input: %s\n", line);
	free(line);
	return (0);
}

