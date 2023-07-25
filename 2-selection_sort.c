#include "sort.h"

/**
 * selection_sort - function sorts an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, temp;
	int print_signal;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		print_signal = 0;
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				print_signal = 1;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		if (print_signal == 1)
			print_array(array, size);
	}
}
