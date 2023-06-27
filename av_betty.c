#include "shell.h"

/**
 * custom_main - Entry point
 * Return: Always 0 (Success)
 */
int custom_main(void)
{
	int a;
	char digit;

	for (a = 0; a < 10; a++)
	{
		digit = a + '0';
		write(1, &digit, 1);
		write(1, "\n", 1);
	}

	return (0);
}

