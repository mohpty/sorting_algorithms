#include "sort.h"

/**
 * merge - merge arrays
 * @array: array will merged
 * @left: left size
 * @right: right size
 * @temp: new node
 */
void merge(int *array, int *temp, size_t left, size_t right)
{
	size_t i = left, j, mid, k;

	j = mid = (left + right) / 2;
	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	k = left;
	while (k < right)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}

	printf("[Done]: ");
	print_array(array + left, right - left);
}


/**
 * merge_sort_recursive - Recursive function for the top-down merge sort
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @left: Start index of the sub-array
 * @right: End index of the sub-array
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	mid = (right + left) / 2;
	if (right - left < 2)
	{
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, right);
	}
}

/**
 * merge_sort - Swap two nodes.
 * @array: the array.
 * @size: it's size
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));

	if (!temp)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
