#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 *order using the Counting sort.
 * @array: thhe array to be sorted.
 * @size: the size of this array.
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *counting_array, *temp;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}

	counting_array = calloc(max + 1, sizeof(int));
	temp = calloc(size + 1, sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		counting_array[array[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}

	print_array(counting_array, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		temp[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];
	free(temp);
	free(counting_array);
}
