#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * bitonic_swap - swaps to be sorted.
 * @array: array of integer
 * @size: size of array
 * @dir: direction of sorting, ascending or descending
 */
void bitonic_swap(int *array, size_t size, bool dir)
{
	size_t k, i;
	int temp;

	k = size / 2;
	for (i = 0; i < k; i++)
	{
		if ((array[i] > array[i + k]) == dir)
		{
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
		}
	}
}

/**
 * bitonic_merge - merges two subarrays of the array in the given direction
 * @array: array to be merged
 * @count: size of the subarrays to be merged
 * @co: starting index of the first subarray
 * @dir: sorting direction (true for ascending, false for descending)
 */
void bitonic_merge(int *array, size_t count, size_t co, bool dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		bitonic_swap(array, count, dir);
		bitonic_merge(array, k, co, dir);
		bitonic_merge(array + k, k, co, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the array in the given direction
 * @array: The array to be sorted
 * @count: Size of the subarray to be sorted
 * @co: Starting index of the first subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t count, size_t co, bool dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count, co, dir ? "UP" : "DOWN");
		print_array(array, count);

		bitonic_sort_recursive(array, k, co, true);
		bitonic_sort_recursive(array + k, k, co, false);
		bitonic_merge(array, count, co, dir);

		printf("Result [%lu/%lu] (%s):\n", count, co, dir ? "UP" : "DOWN");
		print_array(array, count);
	}
}

/**
 * bitonic_sort - sorts array of integers using Bitonic sort
 * @array: array to be sorted
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	bitonic_sort_recursive(array, size, size, true);
}
