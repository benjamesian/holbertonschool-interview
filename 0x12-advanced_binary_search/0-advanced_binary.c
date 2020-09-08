#include "search_algos.h"

/**
 * print_array - convenience function for printing an array
 * @array: array to print
 * @size: size of the array
 */
void print_array(int *array, size_t size)
{
	printf("Searching in array: ");
	do {
		printf("%d", *array++);
	} while (--size && printf(", "));
	putchar('\n');
}

/**
 * helper - find least index of num in array
 * @array: array to search
 * @value: value to search for
 * @left: track index of value
 * @right: track index of value
 * Return: index of value
 */
int helper(int *array, int value, size_t left, size_t right)
{
	size_t mid = left + (right - left) / 2;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (array[mid] < value)
		return (helper(array, value, mid + 1, right));
	if (array[mid] >= value)
		return (helper(array, value, left, mid));
	return (-1);
}

/**
 * advanced_binary - find least index of num in array
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 * Return: index of value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (helper(array, value, 0, size - 1));
}
