#include "shell.h"
/**
 * execute_command - Execute a shell command
 * @command: The command to execute
 * @env: The environment variables
 */
void execute_command(char *command, char **env)
{
	char *argv[Max_Command];
	int b = 0;

	argv[b] = strtok(command, " ");

	while (argv[b])
	{
		b++;
		argv[b] = strtok(NULL, " ");
	}

	if (_strcmp(argv[0], "env") == 0)
	{
		print_environment_variables(env);
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	else
	{
		execute_external_command(argv, env);
	}
}
