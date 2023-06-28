#include "shell.h"
/**
 * customed_main - entry point
 * Return: 0
 */
int customed_main(void)
{
	char _newline = '\n';

	write(STDOUT_FILENO, &newline, 1);
	return (0);
}

