#include "sort.h"

/**
 * bubble_sort - function sorts an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, signal;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		signal = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				signal = 1;
				print_array(array, size);
			}
		}
		if (signal == 0)
			break;
	}
}
