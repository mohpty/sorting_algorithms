#include "sort.h"
#include <stdint.h>

int getmax(int *array, int size)
{
	int i, max;

	max = array[0];
        for (i = 1; i < size; i++)
	{
                if (array[i] > max)
                        max = array[i];
	}
	return (max);
}
/**
 * countingsort - perform counting sort.
 * @array: array to be sorted
 * @size: size of array
 * @exp: Current significant
 */
void countingsort(int *array, int size, int exp)
{
	int *o = malloc(size * sizeof(int));
	int i, count[10] = {0};


	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		o[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = o[i];
	}
	free(o);
}

/**
 * radix_sort - sort an array using the LSD radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int *output, max, exp;

	/*max = array[0];*/
	if (!array || size < 2)
		return;

	/*for (i = 1; (size_t)i < size; i++)
		if (array[i] > max)
			max = array[i];*/
	max = getmax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingsort(array, size, exp);
		print_array(array, size);
	}
	free(output);
}
