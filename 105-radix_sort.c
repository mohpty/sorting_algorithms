#include "sort.h"
#include <stdint.h>

/**
 * countingsort - perform counting sort.
 * @array: array to be sorted
 * @size: size of array
 * @exp: Current significant
 */
void countingsort(int *array, int size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int i, count[10] = {0};


	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - sort an array using the LSD radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int i, max, exp;

	max = array[0];
	if (!array || size < 2)
		return;

	for (i = 1; (size_t)i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingsort(array, size, exp);

		for (i = 0; (size_t)i < size; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}
