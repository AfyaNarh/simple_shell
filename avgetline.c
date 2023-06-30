#include "shell.h"
/**
 * our_getline - Reads a line of input from a file stream
 * @linebuffer: Pointer to the buffer containing the line
 * @m: Pointer to the size of the buffer
 * @stream: File stream to read input from
 * Return: The number of characters read
 */
ssize_t our_getline(char **linebuffer, size_t *m, FILE *stream)
{
	size_t i;
	size_t status = 0;
	ssize_t readbytes;
	char *fornow = NULL;

	if (*linebuffer == NULL)
	{
		*m = 128;
		*linebuffer = malloc(*m);

		if (*linebuffer == NULL)
			return (-1);
	}

	for (i = 0; i < status; i++)
		fornow[i] = (*linebuffer)[i];

	while ((readbytes = read(fileno(stream), &(*linebuffer)[status],
					sizeof(char))) > 0)
	{
		if ((*linebuffer)[status] == '\n')
			break;

		if (status >= *m - 1)
		{
			*m *= 2;
			fornow = malloc(*m);

			if (fornow == NULL)
				return (-1);

			for (i = 0; i < status; i++)
				fornow[i] = (*linebuffer)[i];

			free(*linebuffer);
			*linebuffer = fornow;
		}
		status++;
	}
	if (readbytes == 0 && status == 0)
		return (-1);

	(*linebuffer)[status] = '\0';
	return (status);
}

/**
 * my_getline - Reads a line of input from standard input
 * Return: The input line read
 */
char *my_getline(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_length;

	line_length = our_getline(&line, &line_size, stdin);

	if (line_length == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * mycustom_main - the entry point of the program
 * Return: exit status of the program
 */
int mycustom_main(void)
{
	char *line = my_getline();

	printf("Input: %s\n", line);

	free(line);

	return (0);
}

