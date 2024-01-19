#include "sort.h"

/**
 * merge - merge arrays
 * @array: array will merged
 * @l_size: left size
 * @r_size: right size
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	print_array(array + left, mid - left + 1);

	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];


	print_array(array + left, right - left + 1);
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

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid + 1, right);
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

	temp = malloc(size * sizeof(int));
	if (!array || size < 2)
		return;


	if (!temp)
	{
		return;
	}

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}
