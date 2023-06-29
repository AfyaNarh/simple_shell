#include "shell.h"
/**
 * findExecutable - Finds the executable path for a given command
 * @args: The array containing the command and arguments
 *
 * Description: This function checks if the command is a full path. If not,
 * it searches for the command in the directories listed in the PATH
 * environment variable and updates the args array
 * with the full path of the executable.
 */
void findExecutable(char **args)
{
	if (args[0][0] != '/')
	{
		char *path = getenv("PATH");

		if (path != NULL)
		{
			char *token = strtok(path, ":");

			while (token != NULL)
			{
				char command[MAX_COMMAND];

				snprintf(command, sizeof(command),

						"%s/%s", token, args[0]);
				if (access(command, X_OK) == 0)
				{
					args[0] = strdup(command);
					break;
				}
				token = strtok(NULL, ":");
			}
		}
	}
}
