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
 * custom_main - Entry point.
 * Return: Always 0.
 */
int custom_main(void)
{
	int num1 = 9;
	int num2 = 11;
	int result = sum_numb(num1, num2);

	char buffer[20];
	int length = 0;
	int temp = result;
	int i;

	do {
		temp /= 10;
		length++;
	} while (temp != 0);
	i = length;
	while (result != 0)
	{
		buffer[--i] = '0' + (result % 10);
		result /= 10;
	}

	write(STDOUT_FILENO, "The sum is: ", 12);
	write(STDOUT_FILENO, buffer, length);
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}
