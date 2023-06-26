#include "shell.h"
/**
 * main - starting point
 * @ac: argument to be counted
 * @av: vector of the argument
 * @env: environment variables
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt_command(av, env);
	return (0);
}

