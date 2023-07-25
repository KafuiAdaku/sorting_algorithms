#include "sort.h"

/**
 * swap - function swaps two elementsof an array
 * @array: array whose items are to be sorted
 * @index1: array item at index 1
 * @index2: array item at index 2
 *
 * Return: void
 */

void swap(int *array, size_t index1, size_t index2)
{
	int temp = array[index1];

	array[index1] = array[index2];
	array[index2] = temp;
}

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

	if (array == NULL || size < 2)
		return;

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
