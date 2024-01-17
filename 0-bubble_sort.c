#include "sort.h"

/**
 * _swap - Swap two ints in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int bubble = 0;

	if (array == NULL)
		return;

	if (size < 2)
		return;

	while (bubble == 0)
	{
		bubble = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				_swap(array + i, array + i + 1);
				print_array(array, size);
				bubble = 0;
			}
		}
		len--;
	}
}

