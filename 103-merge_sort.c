#include "sort.h"

/**
 * merge - merge arrays
 * @array: array will merged
 * @temp: temporary node
 * @left: left idx
 * @mid: mid idx
 * @right: right idx
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = left; i < mid && j < right; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	while (i < mid)
	{
	temp[k++] = array[i++];
	}

	while (j < right)
	{
	temp[k++] = array[j++];
	}

	for (i = left; i < right; i++)
	{
	array[i] = temp[i];
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

	if (right - left > 1)
	{
		mid = (left + right) / 2;

		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);

		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Swap two nodes.
 * @array: the array.
 * @size: it's size
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
