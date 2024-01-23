#include "sort.h"

/* Function prototypes */
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);

/**
 * bitonic_sort - Sorts array of integers using Bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_merge - Merges two subarrays of the array in the given direction
 * @array: The array to be merged
 * @low: Starting index of the first subarray
 * @count: Size of the subarrays to be merged
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t k, i;
	int temp;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; ++i)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
				print_array(array, count * 2);
			}
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the array in the given direction
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Size of the subarray to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);

		bitonic_merge(array, low, count, dir);
	}
}
