#include "sort.h"

/**
 * selection_sort- sorts an array of integers in ascending order using
 *		   the Selection sort algorithm
 * @array: pointer to the array to be sorted of type int
 * @size: size of the array (int).
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
		print_array(array, size);
	}
}
