#include "shell.h"
/**
 * sum_numb - Sum two numbers.
 * @a: First number.
 * @v: Second number.
 * Return: The sum of a and v.
 */
int sum_numb(int a, int v)
{
	return (a + v);
}

/**
 * main - Entry point.
 * Return: Always 0.
 */

int main(void)
{
	int num1 = 9;
	int num2 = 11;
	int result = sum_numb(num1, num2);
	char buffer[20];

	int length = snprintf(buffer, sizeof(buffer), "The sum is: %d\n", result);

	write(STDOUT_FILENO, buffer, length);
	return (0);
}
