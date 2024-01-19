#include "sort.h"

/**
 * sift_down - sift down oparation
 * @array: array will sorted
 * @start: the array start
 * @end: array end
 * @size: size of array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t child, swap, root = start;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
		{
			swap = child;
		}
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			swap = child + 1;
		}
		if (swap == root)
		{
			break;
		}
		else
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
	}
}


/**
 * heap_sort - sorts an array using the Heap sort algorithm.
 * @array: array will sorted "heap sort".
 * @size: size of array.
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	for (i = size / 2; i > 0; i--)
	{
		sift_down(array, i - 1, size - 1, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		sift_down(array, 0, end, size);
	}
}
