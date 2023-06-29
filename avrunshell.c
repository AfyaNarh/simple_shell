#include "shell.h"
/**
 * runShell - runs the shell
 */
void runShell(void)
{
	char *string = NULL, *args[MAX_COMMAND];
	size_t n = 0;
	ssize_t character;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			printPrompt();
		}
		character = getline(&string, &n, stdin);
		if (character == -1)
		{
			if (interactive)
			{
				perror("getline");
			}
			break;
		}
		removeTrailingNewline(string);
		tokenizeString(string, args);
		if (_strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			char **env_ptr = environ;

			for (; *env_ptr; env_ptr++)
			{
				write(STDOUT_FILENO, *env_ptr, _strlen(*env_ptr));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
			executeCommand(args);
	}
	free(string);
}

