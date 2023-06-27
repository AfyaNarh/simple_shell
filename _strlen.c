#include "shell.h"
/**
 * _strlen - string length
 * @s: inputed pointer to string
 * Return: length of string
 */
int _strlen(const char *s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}
