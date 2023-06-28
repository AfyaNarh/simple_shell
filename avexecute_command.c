#include "shell.h"

/**
 * execute_command - Execute a shell command
 * @command: The command to execute
 * @env: The environment variables
 */
void execute_command(char *command, char **env)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *argv[2];

		argv[0] = command;
		argv[1] = NULL;
		if (execve(command, argv, env) == -1)
		{
			perror("Error: Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: Waitpid failed");
			exit(EXIT_FAILURE);
		}
	}
}

