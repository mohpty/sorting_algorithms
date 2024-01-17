#include "sort.h"

/**
 * find_max - find the max int in array.
 * @array: the array.
 * @size: the size of the array.
 *
 * Return: imteger
 */
int find_max(const int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending
 *order using the Counting sort.
 * @array: thhe array to be sorted.
 * @size: the size of this array.
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *counting_array;
	size_t index = 0;

	if (array == NULL || size <= 1)
		return;

	max = find_max(array, size);

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max; i++)
	{
		counting_array[i] = 0;
	}
	for (i = 0; (size_t)i < size; i++)
	{
		counting_array[array[i]]++;
	}
	print_array(counting_array, max + 1);

	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[index] = i;
			index++;
			counting_array[i]--;
		}
	}
	free(counting_array);
}
