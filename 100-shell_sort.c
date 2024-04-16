#include "sort.h"
/**
 * shell_sort -  sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: pointer to array
 * @size: size of the array
 **/
void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], a = 0, b = 0, i;
	int n, shell;

	if (!array)
		return;
	while (b * 3 + 1 < size)
	{
		kunth[a] = b * 3 + 1;
		b = kunth[a++];
	}
	for (i = 0; i < a; i++)
	{
		for (b = 0; b < size; b++)
		{
			if ((b + kunth[a - i - 1]) > size - 1)
				break;
			shell = b;
			while (array[shell] > array[shell + kunth[a - i - 1]])
			{
				n = array[shell];
				array[shell] =  array[shell + kunth[a - i - 1]];
				array[shell + kunth[a - i - 1]] = n;
				shell = shell - kunth[a - i - 1];
				if (shell < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
