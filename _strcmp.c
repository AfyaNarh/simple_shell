#include "shell.h"
/**
 * _strcmp - Compare two strings
 * @st1: Pointer to the first string
 * @st2: Pointer to the second string
 *
 * Return: A negative value if the first string is lesser than the second,
 *         a positive value if it's greater, and 0 if they are equal
 */
int _strcmp(const char *st1, const char *st2)
{
	while (*st1 && (*st1 == *st2))
	{
		st1++;
		st2++;
	}

	return (*(unsigned char *)st1 - *(unsigned char *)st2);
}

