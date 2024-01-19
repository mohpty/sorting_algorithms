#include "sort.h"

/**
 * merge - merge arrays
 * @array: array will merged
 * @left: left size
 * @right: right size
 * @temp: new node
 */
void merge(int *array, size_t left, size_t right, int *temp)
{
	size_t i = left, j, k, mid;

	j = mid = (left + right) / 2;
	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (k = left; k < right; k++)
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
 * @left: Start index of the sub-array
 * @right: End index of the sub-array
 * @temp: Temporary array for merging
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
	size_t mid;

	mid = (left + right) / 2;
	if (right - left > 1)
	{

		merge_sort_recursive(temp, left, mid, array);
		merge_sort_recursive(temp, mid, right, array);
		merge(array, left, right, temp);
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
	merge_sort_recursive(temp, 0, size - 1, array);
	free(temp);
}
