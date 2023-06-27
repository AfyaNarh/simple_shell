#include "shell.h"

/**
 * _strcmp - compares two string
 * @st1: first pointer to the string to be compared
 * @st2: second pointer to the string to be compared
 * Return: a negative value if the first string is lesser than the second,
 *  a positive value if it's greater, and 0 if they are equal
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
