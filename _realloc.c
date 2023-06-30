#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/**
 * my_realloc - Reallocates a memory block with a new size
 * @ptr: Pointer to the previously allocated memory block
 * @size: New size for the memory block
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */
void *my_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr != NULL)
	{
		size_t old_size = malloc_usable_size(ptr);

		if (size < old_size)
			old_size = size;

		memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}

	return (new_ptr);
}

