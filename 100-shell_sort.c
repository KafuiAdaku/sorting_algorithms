#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * arr_swap - swaps the position of two elements in an array
 * @a: pointer to the first element.
 * @b: pointer to the second element.
 * Return: Nothing.
 */
void arr_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}

/**
 * shell_sort -  sorts an array of integers in ascending order using
 *		 the Shell sort algorithm, using the Knuth sequence
 * @array: pointer to the array to be sorted
 * @size: size of the array of type int.
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j;

	gap = (int)size / 3;

	if (array == NULL || size < 2)
		return;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] <= array[i])
					arr_swap(&array[i + gap], &array[i]);
				else
					break;
			}
		}
		print_array((const int *)array, size);
	}
}
