#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t c, d;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		min = array + c;
		for (d = c + 1; d < size; d++)
			min = (array[d] < *min) ? (array + d) : min;

		if ((array + d) != min)
		{
			swap_ints(array + d, min);
			print_array(array, size);
		}
	}
}
