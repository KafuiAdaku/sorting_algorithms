#include "sort.h"

/**
 * shell_sort - function sorts an array
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t j, gap;
	int i, print_signal;

	gap = 1;
	while (gap < size)
		gap = 3 * gap + 1;

	for (gap = gap; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i])
					break;
				swap(array, i + gap, i);
				print_signal = 1;
			}
		}
		if (print_signal == 1)
			print_array(array, size);
	}
}
