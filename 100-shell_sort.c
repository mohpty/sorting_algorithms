#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted.
 * @size: saize of the array.
 *
 * Return: non..void.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
