#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counter, k;
	size_t i, j, arr_size;

	if (array == NULL || size <= 1)
		return;
	arr_size = array[0];
	for (i = 0; array[i]; i++)
	{
		if (array[i] > (int)arr_size)
			arr_size = array[i];
	}

	arr_size += 1;

	counter = malloc(arr_size * sizeof(int *));
	if (counter == NULL)
		return;

	for (i = 0; i < arr_size; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]] += 1;

	for (i = 0; i <= arr_size; i++)
		counter[i] += counter[i - 1];

	print_array(counter, arr_size);

	for (i = 1, j = 0; i <= arr_size; i++)
		if (counter[i] != counter[i - 1])
		{
			for (k = 0; k < counter[i] - counter[i - 1]; k++)
				array[j++] = i;
		}
	free(counter);
}
