#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * partition - function to locate the pivot and divide it
 * @array: array to sort
 * @low: lower value of index to sort
 * @hi: higest value
 * @size: size of array
 * Return: index of partition
 */

size_t partition(int *array, ssize_t low, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int pivot, swap;

	pivot = array[hi];
	i = low - 1;
	for (j = low; j <= hi - 1; j++)
	{

		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * re_quick_sort - function that recursive algorithm
 * @array: array to sorted
 * @low: lowest value
 * @hi: higest value
 * @size: size of array
 */

void re_quick_sort(int *array, ssize_t low, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (low < hi)
	{
		pivot = partition(array, low, hi, size);
		re_quick_sort(array, low, pivot - 1, size);
		re_quick_sort(array, (pivot + 1), hi, size);
	}
}

/**
 * quick_sort - sorts an array of int in ascending order using the Quick sort
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	re_quick_sort(array, 0, size - 1, size);
}
