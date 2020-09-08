#include "search_algos.h"

/**
 * print_array - convenience function for printing an array
 * @array: array to print
 * @size: size of the array
 */
void print_array(int *array, size_t size)
{
	printf("Searching in array: ");
	do
	{
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
 */
int helper(int *array, int value, size_t left, size_t right)
{
	size_t mid = (right - left) / 2;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	if (left == right)
		return (array[left] == value ? (int)left : -1);
	if (left + 1 == right)
	{
		if (array[left] == value)
			return (left);
		else if (array[right] == value)
			return (right);
		else
			return (-1);
	}
	if (array[left + mid] < value)
		return helper(array, value, left + mid + 1, right);
	if (array[left + mid] > value)
		return helper(array, value, left, left + mid - 1);
	else
		return helper(array, value, left, mid);
}

/**
 * advanced_binary - find least index of num in array
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 */
int advanced_binary(int *array, size_t size, int value)
{
	return helper(array, value, 0, size - 1);
}
