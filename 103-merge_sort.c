#include "sort.h"

/**
 * merge - merge arrays
 * @array: array will merged
 * @l_size: left size
 * @r_size: right size
 */
void merge(int *array, size_t l_size, size_t r_size)
{
	size_t i, total_size = l_size + r_size;
	size_t left_index = 0, right_index = 0, merged_index = 0;
	int *merged = malloc(total_size * sizeof(int));

	if (merged == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (left_index < l_size && right_index < r_size)
	{
		if (array[left_index] <= array[l_size + right_index])
			merged[merged_index++] = array[left_index++];
		else
			merged[merged_index++] = array[l_size + right_index++];
	}


	while (left_index < l_size)
	{
		merged[merged_index++] = array[left_index++];
	}


	while (right_index < r_size)
	{
		merged[merged_index++] = array[l_size + right_index++];
	}


	for (i = 0; i < total_size; i++)
	{
		array[i] = merged[i];
	}
	free(merged);
}

/**
 * merge_sort - Swap two nodes.
 * @array: the array.
 * @size: it's size
 */
void merge_sort(int *array, size_t size)
{
	size_t left_size, right_size;

	if (size <= 1)
		return;

	left_size = size / 2;
	right_size = size - left_size;

	merge_sort(array, left_size);
	merge_sort(array + left_size, right_size);

	merge(array, left_size, right_size);
}