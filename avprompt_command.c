#include "shell.h"
/**
 * prompt_command - Run the shell prompt and handle commands
 * @av: The command-line arguments
 * @env: The environment variables
 */
void prompt_command(char **av, char **env)
{
	char *string = NULL;
	size_t n = 0;
	ssize_t character;
	char prompt[] = "simple_shell$ ";

	(void)av;

	while (1)
	{
		int a = 0;

		write(STDOUT_FILENO, prompt, _strlen(prompt));
		character = getline(&string, &n, stdin);
		if (character == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		while (string[a])
		{
			if (string[a] == '\n')
				string[a] = '\0';
			a++;
		}
		execute_command(string, env);
	}
	free(string);
}
