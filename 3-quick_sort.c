#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition using the last element as pivot.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
size_t lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot;
	ssize_t above, below;

	above = left - 1;
	pivot = array[right];
	for (below = left; below < right; below++)
	{
		if (array[below] <= pivot)
		{
			above++;
			if (above != below)
			{
				swap_ints(&array[above], &array[below]);
				print_array(array, size);
			}
		}
	}

	if (above + 1 != right)
	{
		swap_ints(&array[above + 1], &array[right]);
		print_array(array, size);
	}

	return (above + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 */
void lomuto_sort(int *array, int left, int right, size_t size)
{
	int part;

	if (left < right)
	{
		part = lomuto_partition(array, left, right, size);
		lomuto_sort(array, left, part - 1, size);
		lomuto_sort(array, part + 1, right, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
