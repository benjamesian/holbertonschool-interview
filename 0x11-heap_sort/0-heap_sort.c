
#include "sort.h"

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * heapify - Recursive function to sort binary tree
 * @array: array to be sorted as binary tree
 * @end: Last node in binary tree
 * @start: First node of binary tree
 * @size: Size of the array to sort
 * Return: 0
 */
void heapify(int *array, size_t start, size_t end, size_t size)
{
	size_t max = start;
	size_t left = 2 * start + 1;
	size_t right = 2 * start + 2;

	if (!array || size < 2)
		return;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (start != max)
	{
		swap(&array[start], &array[max]);
		print_array(array, size);
		heapify(array, max, end, size);
	}
}

/**
 * heap_sort - Sorting array using heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	ssize_t idx;

	if (!array || size < 2)
		return;

	for (idx = size / 2; idx >= 0; idx--)
		heapify(array, idx, size, size);
	for (idx = size - 1; idx >= 0; idx--)
	{
		swap(&array[idx], &array[0]);
		if (idx)
			print_array(array, size);
		heapify(array, 0, idx, size);
	}
}

