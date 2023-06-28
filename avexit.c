#include "shell.h"

/**
 * read_wrapper - Read data from a file descriptor.
 * @fd: File descriptor to read from.
 * @buf: Buffer to store the read data.
 * @count: Maximum number of bytes to read.
 *
 * Return: Number of bytes read, or -1 on error.
 */
ssize_t read_wrapper(int fd, void *buf, size_t count)
{
	ssize_t bytes_read = read(fd, buf, count);

	return (bytes_read);
}

/**
 * write_wrapper - Write data to a file descriptor.
 * @fd: File descriptor to write to.
 * @buf: Buffer containing the data to write.
 * @count: Maximum number of bytes to write.
 *
 * Return: Number of bytes written, or -1 on error.
 */
ssize_t write_wrapper(int fd, const void *buf, size_t count)
{
	ssize_t bytes_written = write(fd, buf, count);

	return (bytes_written);
}

/**
 * exit_shell - Exit the shell with the provided status.
 * @status: Exit status.
 */
void exit_shell(int status)
{
	char status_str[10];
	int len = sprintf(status_str, "%d", status);

	write_wrapper(STDOUT_FILENO, "Exiting shell with status ", 26);
	write_wrapper(STDOUT_FILENO, status_str, len);
	write_wrapper(STDOUT_FILENO, "\n", 1);
	_exit(status);
}

