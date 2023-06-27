#include "shell.h"
/**
 * print_environment_variables - displays environment variables
 * @env: environment variables
 */
void print_environment_variables(char **env)
{
	char **env_ptr = env;

	for (; *env_ptr; env_ptr++)
	{
		write(STDOUT_FILENO, *env_ptr, _strlen(*env_ptr));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * execute_external_command - execute inputed external commands
 * @argv: argument vector
 * @env: environment variable
 */
void execute_external_command(char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			char error[] = "%s: No such file or directory\n";

			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, error, _strlen(error));
		}
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
