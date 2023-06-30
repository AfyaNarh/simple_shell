#include "shell.h"

/**
 * handle_exit - Handles the exit command with arguments
 * @arg: The argument passed to the exit command
 *
 * This function takes an argument as a string, converts it to an integer, and
 * uses it as the exit status for the shell.
 *
 * Return: None
 */
void handle_exit(char *arg)
{
	int status = atoi(arg);

	exit(status);
}

/**
 * my_custom_main - Entry point of the program
 * This function reads the user input, parses it to extract the command and
 * argument, and executes the corresponding action. It handles the exit command
 * with arguments, allowing the user to specify an exit status.
 *
 * Return: 0 on success
 */
int my_custom_main(void)
{
	char input[100];
	char *command, *argument;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		read(STDIN_FILENO, input, sizeof(input));

		command = strtok(input, " \n");
		argument = strtok(NULL, " \n");

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				if (argument != NULL)
				{
					handle_exit(argument);
				}
				else
				{
					write(STDOUT_FILENO, "Usage: exit status\n", 20);
				}
			}
			else
			{
				write(STDOUT_FILENO, "Unknown command: ", 17);
				write(STDOUT_FILENO, command, strlen(command));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
	}

	return (0);
}
