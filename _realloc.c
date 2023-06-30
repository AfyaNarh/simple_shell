#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/**
 * my_realloc - Reallocates a memory block with a new size
 * @prev_size: previously allocated memory block
 * @ptr: pointer to previously allocated memory block
 * @cur_size: New size for the memory block
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */
void *my_realloc(void *ptr, unsigned int prev_size, unsigned int cur_size)
{
	if (ptr != NULL && cur_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(cur_size);
	if (cur_size == prev_size)
		return (ptr);
	free(ptr);
	ptr = malloc(cur_size);
	return (ptr);
}
