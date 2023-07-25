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
