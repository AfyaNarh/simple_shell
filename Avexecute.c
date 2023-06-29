#include "shell.h"

/**
 * executeCommand - Executes a command in the shell
 * @args: The command and its arguments
 * Return: The status code of the command
 */
void executeCommand(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		findExecutable(args);
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
