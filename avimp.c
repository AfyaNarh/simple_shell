#include "shell.h"
#define BUFFER_SIZE 256

/**
 * check_path - handles the path
 * @command: name of the command to be checked
 * Return: NULL
 */
void check_path(const char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char command_path[BUFFER_SIZE];

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			write(1, command, _strlen(command));
		return;
	}
	while (dir != NULL)
	{
		snprintf(command_path, BUFFER_SIZE, "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0)
		{
			write(1, command_path, _strlen(command_path));
			return;
		}
		dir = strtok(NULL, ":");
	}
}
