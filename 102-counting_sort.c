#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * max_int - finds the max integer in an array of integers.
 * @array: pointer to the array to search.
 * @size: size of the array of type int.
 * Return: maximum integer value in the array.
 */
int max_int(int array[], size_t size)
{
	int max, i;

	max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - sorts an array of integers in ascending order
 *		   using the Counting sort algorithm.
 * @array: pointer to the array to be sorted of type int *.
 * @size: size of the array of type int.
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int k, i, count;
	int *count_arr, *sorted_arr;

	if (array == NULL || size < 2)
		return;
	k = max_int(array, size);
	count = k + 1;
	count_arr = malloc(sizeof(int) * count);
	if (count_arr == NULL)
		return;
	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < k; i++)
	{
		count_arr[i]  = 0; /*initialize the arrays to zero*/
	}
	for (i = 0; i < (int)size ; i++)
	{
		count_arr[array[i]]++;
	}
	for (i = 1; i <= k ; i++)
	{
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	}
	print_array(count_arr, k + 1);
	for (i = size - 1; i >= 0; i--)
	{
		sorted_arr[--count_arr[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted_arr[i];
	}
	free(count_arr);
	free(sorted_arr);
}
