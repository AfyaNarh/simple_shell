#include "shell.h"

/**
 * tokenizeString - Tokenizes a string into an array of tokens
 * @string: The string to tokenize
 * @args: The array to store the tokens
 *
 * Description: This function splits the input string into tokens based
 * on space as the delimiter.
 * The tokens are stored in the provided args array.
 */
void tokenizeString(char *string, char **args)
{
	int b = 0;
	char *token = strtok(string, " ");

	while (token != NULL && b < MAX_COMMAND - 1)
	{
		args[b++] = token;
		token = strtok(NULL, " ");
	}

	args[b] = NULL;
}
