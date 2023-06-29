#include "shell.h"

/**
 * cd_command - changes the directory
 * @directory: working directory
 */
void cd_command(char *directory)
{
	char *h_directory = getenv("HOME");
	char *p_directory = getenv("OLDPWD");
	char c_directory[1024];

	if (directory == NULL)
	{
		directory = h_directory;
	}
	if (_strcmp(directory, "-") == 0)
	{
		directory = p_directory;
	}
	if (getcwd(c_directory, sizeof(c_directory)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(directory) != 0)
	{
		perror("chdir");
		return;
	}
	if (setenv("OLDPWD", c_directory, 1) != 0)
	{
		perror("setenv");
		return;
	}
	if (getcwd(c_directory, sizeof(c_directory)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (setenv("PWD", c_directory, 1) != 0)
	{
		perror("setenv");
		return;
	}
}

