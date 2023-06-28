#include "shell.h"
/**
 * execute_command - Execute a shell command
 * @command: The command to execute
 * @env: The environment variables
 */
void execute_command(char *command, char **env)
{
	int status;
	char *argv[2];
	pid_t pid = fork();

	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: Fork failed\n", 19);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;
		if (execve(command, argv, env) == -1)
		{
			write(STDERR_FILENO, "Error: Execve failed\n", 21);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			write(STDERR_FILENO, "Error: Waitpid failed\n", 22);
			exit(EXIT_FAILURE);
		}
	}

}
