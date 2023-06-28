#include "shell.h"

/**
 * avstrtok - Custom strtok for multiple delimiters
 * @str: The string to tokenize
 * @delim: The delimiters
 * @save_ptr: Pointer to the save pointer
 *
 * Return: The next token
 */
char *avstrtok(char *str, const char *delim, char **save_ptr)
{
	char *current_token;
	char *next_token;

	if (str != NULL)
		*save_ptr = str;

	current_token = *save_ptr;
	if (current_token == NULL)
		return (NULL);

	next_token = current_token + strcspn(current_token, delim);
	if (*next_token != '\0')
	{
		*next_token = '\0';
		*save_ptr = next_token + 1;
	}
	else
	{
		*save_ptr = NULL;
	}

	return (current_token);
}

