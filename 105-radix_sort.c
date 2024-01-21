#include "sort.h"
#include <stdint.h>

/**
 * getMax - get the maximum value in thearray
 * @array: array to find max
 * @size: size of array
 * Return: max value.
 */
int getMax(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	return (max);
}

/**
 * countSort - perform counting sort.
 * @array: array to be sorted
 * @size: size of array
 * @exp: Current significant
 */
void countSort(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
		print_array(array, size);
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
	int max, exp;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
	}
}
