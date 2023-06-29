#include "shell.h"

/**
 * printPrompt - Prints the shell prompt
 */
void printPrompt(void)
{
	write(STDOUT_FILENO, "Simple shell$ ", 14);
}

/**
 * removeTrailingNewline - Removes the trailing newline character from a string
 * @string: The string to remove the newline from
 */
void removeTrailingNewline(char *string)
{
	size_t length = _strlen(string);

	if (length > 0 && string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
}
