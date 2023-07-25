#include "sort.h"

/**
 * array_swap - swaps the position of two elements in an array
 * @a: pointer to the first element.
 * @b: pointer to the second element.
 * Return: Nothing.
 */
void array_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - divides the array into two sub arrays (partitions) using
 *		      lomuto's algorithm
 * @array: the array to be partitioned
 * @size: size of the array of type int
 * @lb: the lower bound of the array of type int
 * @ub: the upper bound of the array of type int
 * Return: int that represents the location of the pivot elememt
 */
size_t lomuto_partition(int *array, size_t size, int lb, int ub)
{
	int pivot, start, i; /*`i` traverses the array*/

	pivot = array[ub];
	start = lb;

	i = start;
	while (i < ub)
	{
		if (array[i] < pivot)
		{
			if (start < i)
			{
				array_swap(&array[start], &array[i]);
				print_array(array, size);
			}
			start++;
		}
		i++;
	}
	if (array[start] > pivot)
	{
		array_swap(&array[start], &array[ub]);
		print_array(array, size);
	}
	return (start);
}



/**
 * lomuto_sort - sorts an array using lomuto's implementationo of quick sort.
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
 * @lb: start index of the array.
 * @ub: end index of the array.
 * Return: Nothing
 */

void lomuto_sort(int *array, size_t size, int lb, int ub)
{
	int loc;

	if (array == NULL || size < 2)
		return;
	if (ub > lb)
	{
		loc = lomuto_partition(array, size, lb, ub);
		lomuto_sort(array, size, lb, loc - 1);
		lomuto_sort(array, size, loc + 1, ub);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *		using the Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array.
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int lb, ub;

	lb = 0;
	ub = (int)size - 1;

	lomuto_sort(array, size, lb, ub);
}
