#include "shell.h"

/**
 * av_strtok - Implementation of strtok function.
 * @str: The string to be tokenized.
 * @delim: The delimiter characters.
 *
 * Return: Pointer to the next token found in the string.
 */
char *av_strtok(char *str, const char *delim)
{
	char *next_token = NULL;
	char *current_token;
	size_t token_len;

	if (str != NULL)
	{
		next_token = str;
	}
	else
	{
		if (next_token == NULL)
			return (NULL);
		next_token = NULL;
	}
	current_token = next_token;
	token_len = strcspn(current_token, delim);

	next_token = current_token + token_len;

	if (*next_token != '\0')
	{
		*next_token++ = '\0';
	}

	else
	{
		next_token = NULL;
	}

	return (current_token);
}


