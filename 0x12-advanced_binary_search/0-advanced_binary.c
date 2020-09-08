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
 * @size: size of the array
 * @value: value to search for
 * @index: track index of value
 */
int helper(int *array, size_t size, int value, size_t index)
{
	size_t mid = size / 2;

	if (size == 0)
		return (-1);

	print_array(array, size);

	if (array[mid] < value)
	{
		size -= mid + 1;
		index += 1 + size / 2;
		return helper(array + mid + 1, size, value, index);
	}
	if (array[mid] > value)
		return helper(array, mid, value, index - mid + mid / 2);
	if (size == 2)
	{
		if (array[0] == value)
			return (index - 1);
		else if (array[1] == value)
			return (index);
		else
			return (-1);
	}
	else if (size == 1)
		return (index);
	else
		return helper(array, mid + 1, value, index - mid / 2);
}

/**
 * advanced_binary - find least index of num in array
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 */
int advanced_binary(int *array, size_t size, int value)
{
	return helper(array, size, value, size / 2);
}
